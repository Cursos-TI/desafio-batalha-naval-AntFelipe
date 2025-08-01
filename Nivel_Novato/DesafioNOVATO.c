#include <stdio.h>
int main (){
    int tabuleiro[10][10];

    for (int INDEX_1 = 0; INDEX_1 < 10; INDEX_1++) {
        for (int INDEX_0 = 0; INDEX_0 < 10; INDEX_0++) {
            tabuleiro[INDEX_1][INDEX_0] = 0; // Atribui 0 (água) a todos os pontos
        }
    }

    tabuleiro[1][1] = 3;
    tabuleiro[2][1] = 3;
    tabuleiro[3][1] = 3;

    tabuleiro[8][8] = 3;
    tabuleiro[8][7] = 3;
    tabuleiro[8][6] = 3;

int INDEX_1; //linhas
int INDEX_0; //colunas

    printf("TABULEIRO: Batalha Naval!!!\n");
    printf("\n");
    for (INDEX_1 = 0; INDEX_1 <= 9; INDEX_1++)
    {

        for (INDEX_0 = 0; INDEX_0 <= 9; INDEX_0++)
        {
            printf("%d  ", tabuleiro[INDEX_1][INDEX_0]);
        };
        printf("\n");
    };
}