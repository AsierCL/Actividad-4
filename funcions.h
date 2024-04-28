#ifndef FUNCIONS_H
#define FUNCIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "./TAD/vectordinamico.h"

void imprimirMonedasDispoñibles(char *arquivo_leer);
int leerArquivo(vectorD *valores_monedas, char *arquivo_leer, char *tipo_moneda);

int cambioSinStock(int x, vectorD valor, vectorD *solucion); 
int cambioConStock(int x, vectorD valor, vectorD *solucion, vectorD *stock); 
void aumentarStock(vectorD *stock, int n);
void imprimirMonedas(vectorD valor, vectorD solucion);

void actualizar_stock(vectorD stock, char *arquivo_actualizar, char *tipo_moneda);

#endif