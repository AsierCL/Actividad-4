#ifndef FUNCIONS_H
#define FUNCIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./TAD/vectordinamico.h"


void leerArquivo(vectorD *valores_monedas, char *arquivo_leer, char *tipo_moneda);

void devolverCambioIlimitado();

void devolverCambioLimitado();


#endif