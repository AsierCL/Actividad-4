#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./TAD/vectordinamico.h"

#define MAX_LINE_LENGTH 1000
#define MAX_TOKENS 20

void leerArquivo(vectorD *valores_monedas, char *arquivo_leer, char *tipo_moneda) {
    FILE *file;
    int check = 0;
    char line[MAX_LINE_LENGTH];
    int numbers[MAX_TOKENS];
    char *token;
    int count, i;

    // Abre el archivo para lectura
    file = fopen(arquivo_leer, "r");
    if (file == NULL) {
        perror("No se pudo abrir el archivo");
        exit(1);
    }


    // Lee el archivo línea por línea
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Verifica si la línea comienza con "libra"
        if (strstr(line, tipo_moneda) != NULL) {
            count = 0;
            // Divide la línea en tokens usando el espacio como delimitador
            token = strtok(line, " ");
            // Busca "libra" en la línea
            while (token != NULL && strcmp(token, tipo_moneda) != 0) {
                token = strtok(NULL, " ");
            }
            // Si encuentra "libra", almacena los números siguientes en el vector
            if (token != NULL) {
                token = strtok(NULL, " ");
                while (token != NULL && count < MAX_TOKENS) {
                    numbers[count++] = atoi(token);
                    token = strtok(NULL, " ");
                }
                
                CreaVector(valores_monedas, count);
                check = 1;
                // Guarda los números almacenados
                for (i = 0; i < count; i++) {
                    AsignaVector(valores_monedas, i, numbers[i]);
                }
                printf("\n");
            }
        }
    }
    

    // Cierra el archivo
    fclose(file);

    if (check == 0){
        printf("\x1b[31m\nNon se atopou a moeda\x1b[0m\n");
        exit(1);
    }
}

int cambioSinStock(int x, vectorD valor, vectorD *solucion, int n) {
    // Inicializar solucion[]
    CreaVector(solucion,n);
    for (int i = 0; i < n; i++) 
        //solucion[i] = 0;
        AsignaVector(solucion, i, 0);
    
    int i = 0, suma = 0;

    // Mientras la suma no supere x y hayan denominaciones disponibles
    while (suma < x && i < n) {
        // Si se puede añadir la denominación actual sin pasarse de x
        if (suma + recuperar(valor, i) <= x) {
            AsignaVector(solucion, i, recuperar(*solucion, i)+1);
            suma += recuperar(valor, i);
        } else {
            // Pasar a la siguiente denominación
            i++;
        }
    }

    // Si se logró el cambio exacto
    if (suma == x) {
        return 1;
    } else {
        // Reinicializar solucion[] y retornar 0
        for (int i = 0; i < n; i++) 
            AsignaVector(solucion, i, 0);
        return 0;
    }
}



int cambioConStock(int x, vectorD valor, vectorD *solucion, vectorD *stock, int n) {
    // Inicializar solucion[]
    CreaVector(solucion,n);
    for (int i = 0; i < n; i++) 
        //solucion[i] = 0;
        AsignaVector(solucion, i, 0);
    
    int i = 0, suma = 0;

    // Mientras la suma no supere x y hayan denominaciones disponibles
    while (suma < x && i < n) {
        // Si se puede añadir la denominación actual sin pasarse de x
        if (suma + recuperar(valor, i) <= x) {
            if(recuperar(*stock, i) == 0){
                printf("\x1b[31m\nNon hai suficiente stock dispoñible\x1b[0m\n");
                return 0;
            }
            AsignaVector(solucion, i, recuperar(*solucion, i)+1);
            AsignaVector(stock, i, recuperar(*stock, i)-1);
            suma += recuperar(valor, i);
        } else {
            // Pasar a la siguiente denominación
            i++;
        }
    }

    // Si se logró el cambio exacto
    if (suma == x) {
        return 1;
    } else {
        // Reinicializar solucion[] y retornar 0
        for (int i = 0; i < n; i++) {
            AsignaVector(solucion, i, 0);
        }
        printf("\x1b[31m\nNon se obtivo o cambio exacto\x1b[0m\n");
        return 0;
    }
}

void aumentarStock(vectorD *stock, int n){
    for (int i = 0; i<n; i++){
        AsignaVector(stock, i, recuperar(*stock, i)+10);
    }
}

void imprimirMonedas(vectorD valor, vectorD solucion){
    int n = tamano(valor);
    for(int i=0;i<n;i++){
        printf("\n%d Moneda de %d",recuperar(solucion,i),recuperar(valor,i));
    }
    fflush(stdout);
}

