#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "./TAD/vectordinamico.h"
#include "./funcions.h"


int main(int argc, char** argv){
    /// Global variables
    char limite_moedas, opcion;
    char tipo_moeda[32];
    vectorD solucion, moedas, stock;




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
                    ///devolverCambioIlimitado();
                    sleep(2);
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
            do{
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
                        ///devolverCambioLimitado();
                        sleep(2);
                        system("clear");
                    break;
                        
                    case 'b':

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