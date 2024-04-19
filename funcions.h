#ifndef FUNCIONS_H
#define FUNCIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./TAD/vectordinamico.h"


void leerArquivo(vectorD *valores_monedas, char *arquivo_leer, char *tipo_moneda);

int cambioSinStock(int x, vectorD valor, vectorD *solucion, int n); 
int cambioConStock(int x, vectorD valor, vectorD *solucion, vectorD *stock, int n); 
void aumentarStock(vectorD *stock, int n);
void imprimirMonedas(vectorD valor, vectorD solucion);

#endif