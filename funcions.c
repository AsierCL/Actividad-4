#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./TAD/vectordinamico.h"

#define MAX_LINE_LENGTH 1000
#define MAX_TOKENS 20

void leerArquivo(vectorD *valores_monedas) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int numbers[MAX_TOKENS];
    char *token;
    char tipo_moneda[16];
    int count, i;

    // Abre el archivo para lectura
    file = fopen("monedas.txt", "r");
    if (file == NULL) {
        perror("No se pudo abrir el archivo");
        exit(1);
    }

    system("clear");
    printf("\n-----------------------------------------------------------\n");
    printf("Introduce a moeda coa que queres traballar (en minúsculas):\n");
    printf("-----------------------------------------------------------\n");
    scanf("%s",&tipo_moneda);

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
                
                // Imprime los números almacenados
                printf("Números después de 'libra': ");
                for (i = 0; i < count; i++) {
                    //printf("%d ", numbers[i]);
                    AsignaVector(valores_monedas, i, numbers[i]);
                }
                printf("\n");
            }
        }
    }

    // Cierra el archivo
    fclose(file);
}

int cambio(int x, int valor[], int solucion[], int n) {
    // Inicializar solucion[]
    for (int i = 0; i < n; i++) 
        solucion[i] = 0;
    
    int i = 0, suma = 0;

    // Mientras la suma no supere x y hayan denominaciones disponibles
    while (suma < x && i < n) {
        // Si se puede añadir la denominación actual sin pasarse de x
        if (suma + valor[i] <= x) {
            solucion[i]++;
            suma += valor[i];
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
            solucion[i] = 0;
        return 0;
    }
}


void devolverCambioIlimitado();

void devolverCambioLimitado();

