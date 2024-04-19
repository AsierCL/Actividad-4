#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "./TAD/vectordinamico.h"
#include "./funcions.h"


int main(int argc, char** argv){
    /// Global variables
    char limite_moedas, opcion;
    char tipo_moneda[32];
    vectorD solucion, moedas, stock;
    int cambio_a_devolver;


    // IDEA1
    /* Volver a funcion int leerArquivo, e facer un while coa condicion de que se devolve 1, 
    que repita a pregunta para facer que volva a introducir a moeda*/
    // IDEA2
    /* Que se de unha lista cas moedas dispoñibles no arquivo,
    para que o usuario sepa cal escoller */

    system("clear");
    printf("\n-----------------------------------------------------------\n");
    printf("Introduce a moeda coa que queres traballar (en minúsculas):\n");
    printf("-----------------------------------------------------------\n");
    scanf("%s",&tipo_moneda);

    leerArquivo(&moedas, "monedas.txt", tipo_moneda);
    // CHECK imprimir(moedas);


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
                    cambioSinStock(cambio_a_devolver, moedas, &solucion, longitudVector(moedas));
                    imprimirMonedas(moedas, solucion);
                    sleep(5);
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
            leerArquivo(&stock, "stock.txt", tipo_moneda);
            do{
                // CHECK 
                imprimir(stock);
                fflush(stdout);
                system("clear");
                printf("\n---------------------------------------\n");
                printf("           MOEDAS LIMITADAS\n");
                printf("\na) Dar cambio\nb) Aumentar stock\ns) Sair\n");
                printf("---------------------------------------\n");
                printf("\nOpción: ");
                scanf(" %c", &opcion);
                
                // Entramos no switch
                switch (opcion) {
                    case 'a': 
                        system("clear");
                        printf("-----------------");
                        printf("\n| a) Dar cambio |\n");
                        printf("-----------------\n");
                        printf("Canto cambio tes que dar? ");
                        scanf("%d", &cambio_a_devolver);
                        
                        if (cambioConStock(cambio_a_devolver, moedas, &solucion, &stock, longitudVector(moedas))){
                            imprimirMonedas(moedas, solucion);
                        }

                        sleep(2);
                        system("clear");
                    break;

                    case 'b':
                        system("clear");
                        printf("-----------------");
                        printf("\nStock aumentado\n");
                        printf("-----------------\n");
                        printf("Novo stock:");
                        imprimirMonedas(moedas, stock);
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
    
        case 's':
            printf("\nSaíndo do programa...\n");
        break;

        default:
            printf("\x1b[31m\nOpción incorrecta\x1b[0m\n");
            sleep(2);
        break;
    }
}