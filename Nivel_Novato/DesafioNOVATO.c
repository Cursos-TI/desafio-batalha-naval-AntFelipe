#include <stdio.h>
int main (){
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 3, 3, 3},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

int INDEX_1; //linhas
int INDEX_0; //colunas

    printf("TABULEIRO: Batalha Naval!!!\n");
    printf("\n");
    for (INDEX_1 = 0; INDEX_1 <= 9; INDEX_1++)
    {

        for (INDEX_0 = 0; INDEX_0 <= 9; INDEX_0++) /* O valor de index_0 é configurado dentro do loop de modo a 
                                                    sempre que o loop externo voltar a rodar o valor não ficará 
                                                    salvo fixamente, e voltará a ser 0. Se adicionasse externamente
                                                    o valor, após a soma, ficaria sempre como 10 (não sendo lido) e 
                                                    o printf saíria vazio! */
        {
            printf("%d  ", tabuleiro[INDEX_1][INDEX_0]); //2 espaços para organizar
        };

        printf("\n");
        
    };
}