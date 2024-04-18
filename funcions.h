#ifndef FUNCIONS_H
#define FUNCIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./TAD/vectordinamico.h"


void leerArquivo(vectorD *valores_monedas, char *arquivo_leer, char *tipo_moneda);

int cambioSinStock(int x, vectorD valor, vectorD solucion, int n); 
void imprimirSolucion(vectorD valor, vectorD solucion);



void devolverCambioIlimitado();

void devolverCambioLimitado();


#endif