#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




int main(int argc, char** argv){
    /// Global variables
    char limited_money, opcion;



    system("clear");
    printf("\n-----------------------------------------------\n");
    printf("                 MODO DE USO                     \n");
    printf("\na) Moedas ilimitadas     b) Moedas limitadas\n");
    printf("-----------------------------------------------\n");
    printf("\nOpción: ");
    scanf(" %c", &limited_money);
    switch (limited_money)
    {
    case 'a':
    
    break;
    
    case 'b':
        do{
            system("clear");
            printf("\n---------------------------------------\n");
            printf("           MOEDAS LIMITADAS\n");
            printf("\na) Dar cambio     b) Aumentar stock\n");
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
                    ///devolverCambio();
                    sleep(2);
                    system("clear");
                break;
                
                case 'b':

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
    }


}