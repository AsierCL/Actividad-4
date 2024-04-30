#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../TAD/vectordinamico.h"

#define MAX_LINE_LENGTH 32
#define MAX_TOKENS 32

void imprimirMonedasDispoñibles(char *arquivo_leer){
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;

    // Abre o archivo para lectura
    file = fopen(arquivo_leer, "r");
    if (file == NULL) {
        perror("Non se poido abrir o arquivo");
        exit(1);
    }

    // Lee el archivo línea por línea
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        token = strtok(line, " ");
        printf("%s ",token);
        while (token != NULL) {
            token = strtok(NULL, " ");
        }
    }
    printf("\n");

    // Cerra o arquivo
    fclose(file);
}

int leerArquivo(vectorD *valores_monedas, char *arquivo_leer, char *tipo_moneda) {
    FILE *file;
    int check = 1;
    char line[MAX_LINE_LENGTH];
    int numbers[MAX_TOKENS];
    char *token;
    int count, i;

    // Abre o arquivo para lectura
    file = fopen(arquivo_leer, "r");
    if (file == NULL) {
        perror("\x1b[31m\nNon se poido abrir o arquivo\x1b[0m\n");
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
                check = 0;
                // Guarda los números almacenados
                for (i = 0; i < count; i++) {
                    AsignaVector(valores_monedas, i, numbers[i]);
                }
                printf("\n");
            }
        }
    }
    

    // Cerra o archivo
    fclose(file);

    if (check == 1){
        printf("\x1b[31m\nNon se atopou a moeda\x1b[0m\n");
        sleep(2);
        return 1;
    }else{
        return 0;
    }
}

int cambioSinStock(int x, vectorD valor, vectorD *solucion) {
    int n = longitudVector(valor);
    // Inicializar solucion[]
    CreaVector(solucion,n);
    for (int i = 0; i < n; i++) 
        //solucion[i] = 0;
        AsignaVector(solucion, i, 0);
    
    int i = 0, suma = 0;

    // Mentras a suma non supere x e haxa valores disponibles
    while (suma < x && i < n) {
        // Si se pode añadir o valor actual sin pasarse de x
        if (suma + recuperar(valor, i) <= x) {
            AsignaVector(solucion, i, recuperar(*solucion, i)+1);
            suma += recuperar(valor, i);
        } else {
            // Pasar ao seguinte valor
            i++;
        }
    }

    // Se ten o cambio exacto
    if (suma == x) {
        return 1;
    } else {
        // Reiniciaar solucion[] e devolver 0
        for (int i = 0; i < n; i++) 
            AsignaVector(solucion, i, 0);
        return 0;
    }
}

int cambioConStock(int x, vectorD valor, vectorD *solucion, vectorD *stock) {
    int n = longitudVector(valor);
    // Inicializar solucion[]
    CreaVector(solucion,n);
    for (int i = 0; i < n; i++) 
        //solucion[i] = 0;
        AsignaVector(solucion, i, 0);
    
    int i = 0, suma = 0;

    // Mentras a suma non supere x e haxa valores disponibles
    while (suma < x && i < n) {
        // Si se pode añadir o valor actual sin pasarse de x
        if (suma + recuperar(valor, i) <= x) {
            if(recuperar(*stock, i) == 0){
                printf("\x1b[31m\nNon hai suficiente stock dispoñible\x1b[0m\n");
                return 0;
            }
            AsignaVector(solucion, i, recuperar(*solucion, i)+1);
            AsignaVector(stock, i, recuperar(*stock, i)-1);
            suma += recuperar(valor, i);
        } else {
            // Pasar aoseguinte valor
            i++;
        }
    }

    // Se consigueu o cambio
    if (suma == x) {
        return 1;
    } else {
        // Reiniciar solucion[] e devolver 0
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

void actualizar_stock(vectorD stock, char *arquivo_actualizar, char *tipo_moneda){
    //Variables
    FILE *file;
    FILE *file_2;
    int check = 0;
    char line[MAX_LINE_LENGTH];
    int numbers[MAX_TOKENS];
    char *token;
    long posicion = 0;

    //Abro os dous arquivos
    file = fopen(arquivo_actualizar, "r");
    file_2 = fopen("temp.txt", "w");


    while(fgets(line,MAX_LINE_LENGTH,file)!=NULL){
        if(strstr(line, tipo_moneda)!=NULL){

            fprintf(file_2, "%s", tipo_moneda);
            for(int i=0;i<longitudVector(stock);i++){
                fprintf(file_2, " %d", Componentei(stock,i));
            }
            fprintf(file_2, "\n");
        }
        else{
            fprintf(file_2, line);
        }
    }


    //Reemplazo o archivo
    remove(arquivo_actualizar);
    rename("temp.txt", arquivo_actualizar);

    fclose(file);
    fclose(file_2);
}