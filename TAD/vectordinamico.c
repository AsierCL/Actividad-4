#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef int TELEMENTO;

typedef struct {
    TELEMENTO *datos;
    unsigned long int tam;
} STVECTOR;

typedef STVECTOR *vectorD;

/*Función CreaVector: asigna memoria y devuelve la asignación al vector*/
void CreaVector(vectorD *v1, unsigned long int tam1) {
    //LiberaVector(v1);
    *v1 = (vectorD) malloc(sizeof (STVECTOR));
    (*v1)->datos = (TELEMENTO*) malloc(tam1 * sizeof (TELEMENTO));
    (**v1).tam = tam1;
}

/*Función AsignaVector: Llena una posición del vector con un valor*/
void AsignaVector(vectorD *v1, unsigned long int posicion, TELEMENTO valor) {
    *( (*v1) ->datos + posicion) = valor;
}


bool EsNulo(vectorD v1) {
    if (v1 == 0)
        return true;
    return false;
}

void LiberaVector(vectorD *v1) {
    if (!EsNulo(*v1)) {
        /*Primero liberamos el bloque al que apunta datos*/
        free((*v1)->datos);
        /*Y después liberamos la estructura*/
        free(*v1);
        /*Volvemos a inicializar el puntero a 0*/
        *v1=0;
    }
}

TELEMENTO Componentei(vectorD v1,unsigned long int posicion){
    if (!EsNulo(v1))
        if (posicion < v1->tam)
            return *(v1->datos+posicion);
}

unsigned long int tamano(vectorD v1){
    return v1->tam;
}


//////////////////////////
///  As miñas funcións ///
//////////////////////////

void liberar(vectorD *vectorV1) {
    if (!EsNulo(*vectorV1)) {
        /*Primero liberamos el bloque al que apunta datos*/
        free((*vectorV1)->datos);
        /*Y después liberamos la estructura*/
        free(*vectorV1);
        /*Volvemos a inicializar el puntero a 0*/
        *vectorV1=0;
    }
}

TELEMENTO recuperar(vectorD v1, unsigned long int posicion){
    if (!EsNulo(v1))
        if (posicion < v1->tam)
            return *(v1->datos+posicion);
}

unsigned long int longitudVector(vectorD v1){
    if (!EsNulo(v1)){
        return v1->tam;
    }
}


void imprimir(vectorD v1){
    TELEMENTO j;
    unsigned long int longitud = longitudVector(v1);
    unsigned long int i;
    for (i = 0; i<longitud; i++){
        j = recuperar(v1,i);
        printf("%d ",j);
    }
}
