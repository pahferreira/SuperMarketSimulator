/// Neil, Paulo Henrique, Willian Abdon

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "supermarket.h"
#define SIMULATION_TIME 720


int main(){
    int timer, next, i;
    char opt;
    tlista boxs;

    printf("-------------------------------------------------------------------------------------------------\n");
    printf("                                    SUPERT MARKET SIMULATOR                                      \n");
    printf("-------------------------------------------------------------------------------------------------\n\n");
    printf("Quantidade de caixas                   [6]\n\n");
    printf("Tempo para chegada de novo cliente     [1 - 5]\n\n");
    printf("Quantidade de produtos                 [1 - 101]\n\n");
    printf("Tempo de atendimento no caixa          [Produtos * 0.28]  (Arrendondado para cima) \n\n");

    printf("[ENTER] Start Simulation               [ESC] Exit\n");
    if((opt = getch()) == 27) return 0;
    srand(time(NULL));


    startBoxs(&boxs);
    inserir(&boxs, &next);

    for(timer = 0; timer < SIMULATION_TIME; timer++){

            if(next == 0)
                inserir(&boxs, &next);

            system("cls");
            printf("_________________________________________________________________________________________________\n");
            printf("   | Cx. R | "); imprimirFila(boxs, 1); printf("\n");
            printf("_________________________________________________________________________________________________\n\n");
            printf("   | Cx. 1 | "); imprimirFila(boxs, 2); printf("\n");
            printf("_________________________________________________________________________________________________\n\n");
            printf("_________________________________________________________________________________________________\n");
            printf("   | Cx. 2 | "); imprimirFila(boxs, 3); printf("\n");
            printf("_________________________________________________________________________________________________\n\n");
            printf("_________________________________________________________________________________________________\n");
            printf("   | Cx. 3 | "); imprimirFila(boxs, 4); printf("\n");
            printf("_________________________________________________________________________________________________\n\n");
            printf("_________________________________________________________________________________________________\n");
            printf("   | Cx. 4 | "); imprimirFila(boxs, 5); printf("\n");
            printf("_________________________________________________________________________________________________\n\n");
            printf("_________________________________________________________________________________________________\n");
            printf("   | Cx. 5 | "); imprimirFila(boxs, 6); printf("\n");
            printf("_________________________________________________________________________________________________\n\n");

            countTime(&boxs);
            next--;
            //getch();

    }

    printf("\n-------------------------------------------------------------------------------------------------\n");
    printf("                                         DADOS OBTIDOS                                           \n");
    printf("-------------------------------------------------------------------------------------------------\n\n");
    printf("* Tamanho maximo de fila *\n\n");
    for(i = 0; i < CAIXAS; i++){
        i == 0 ? printf("Cx. %c : ", 'R') : printf("Cx. %d : ", i);
        printf("%d\n", boxs.maxSize[i]);
    }

    printf("\n* Tamanho de espera maxima *\n\n");
    for(i = 0; i < CAIXAS; i++){
        i == 0 ? printf("Cx. %c : ", 'R') : printf("Cx. %d : ", i);
        printf("%d min\n", boxs.maxTime[i]);
    }


    return 0;
}
