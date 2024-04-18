#include <stdio.h>
#include <stdlib.h>

#include "./TAD/vectordinamico.h"

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

