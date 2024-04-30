#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "./TAD/vectordinamico.h"
#include "./Funcions/funcions.h"


int main(int argc, char** argv){
    /// Variables globales
    char limite_moedas, opcion;
    char tipo_moneda[32];
    vectorD solucion, moedas, stock;
    int cambio_a_devolver;
    
    //Archivos
    char archivo_monedas[32];
    char archivo_stock[32];

    //Posibilidad de pasar os arquivos como args de entrada
    if(argc == 3){
        strcpy(archivo_monedas, argv[1]);
        strcpy(archivo_stock, argv[2]);
    }
    else{//Arquivos default
        strcpy(archivo_monedas, "monedas.txt");
        strcpy(archivo_stock, "stock.txt");
    }

    /* Primeira interfaz
    Escolle moneda */
    do{
    system("clear");
    printf("\n-----------------------------------------------------------\n");
    printf("Escribe a moeda coa que queres traballar\n");
    printf("Opcións dispoñibles: ");
    imprimirMonedasDispoñibles(archivo_monedas);
    printf("-----------------------------------------------------------\n");
    scanf("%s",&tipo_moneda);
    }while(leerArquivo(&moedas, archivo_monedas, tipo_moneda));

    /* Segunda interfaz
    Modo de uso */
    system("clear");
    printf("\n-----------------------------------------------\n");
    printf("                 MODO DE USO                     \n");
    printf("\na) Moedas ilimitadas     b) Moedas limitadas  \n");
    printf("-----------------------------------------------\n");
    printf("\nCambio: ");
    scanf(" %c", &limite_moedas);
    switch (limite_moedas){
        case 'a':
            do{
                system("clear");
                printf("\n----------------------------------\n");
                printf("       MOEDAS ILIMITADAS            \n");
                printf("\na) Devolver cambio\ns) Saír\n");
                printf("----------------------------------\n");
                printf("\nOpción: ");
                scanf(" %c", &opcion);

                switch (opcion){
                case 'a':
                    system("clear");
                    printf("-----------------");
                    printf("\n| a) Dar cambio |\n");
                    printf("-----------------\n");
                    printf("Canto cambio tes que dar? ");
                    scanf("%d", &cambio_a_devolver);
                    if (cambioSinStock(cambio_a_devolver, moedas, &solucion)){
                        imprimirMonedas(moedas, solucion);
                    }
                    sleep(4);
                    system("clear");
                break;
                
                case 's':
                    printf("\nSaíndo do programa...\n");
                break;

                default:
                    printf("\x1b[31m\nOpción incorrecta\x1b[0m\n");
                    sleep(2);
                break;
                }
            }while (opcion != 's');
        break;
        
        case 'b':
            leerArquivo(&stock, archivo_stock, tipo_moneda);
            do{
                system("clear");
                printf("\n---------------------------------------\n");
                printf("           MOEDAS LIMITADAS\n");
                printf("\na) Dar cambio\nb) Aumentar stock\ns) Sair\n");
                printf("---------------------------------------\n");
                printf("\nOpción: ");
                scanf(" %c", &opcion);
                
                switch (opcion) {
                    case 'a': 
                        system("clear");
                        printf("-----------------");
                        printf("\n| a) Dar cambio |\n");
                        printf("-----------------\n");
                        printf("Canto cambio tes que dar? ");
                        scanf("%d", &cambio_a_devolver);
                        
                        if (cambioConStock(cambio_a_devolver, moedas, &solucion, &stock)){
                            imprimirMonedas(moedas, solucion);
                        }
                        sleep(4);
                        system("clear");
                    break;

                    case 'b':
                        system("clear");
                        aumentarStock(&stock, longitudVector(stock));
                        printf("-----------------");
                        printf("\nStock aumentado\n");
                        printf("-----------------\n");
                        printf("Novo stock:");
                        imprimirMonedas(moedas, stock);
                        sleep(4);
                    break;

                    case 's':
                        printf("\nSaíndo do programa...\n");
                    break;

                    default:
                        printf("\x1b[31m\nOpción incorrecta\x1b[0m\n");
                        sleep(2);
                    break;
                }
                while (getchar() != '\n');
            } while (opcion != 's');
        break;

        default:
            printf("\x1b[31m\nOpción incorrecta\x1b[0m\n");
            sleep(2);
        break;
        actualizar_stock(stock, archivo_stock, tipo_moneda);
    }

    //Libero memoria
    LiberaVector(&stock);
    LiberaVector(&moedas);
    LiberaVector(&solucion);
}