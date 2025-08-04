#include <stdio.h>
int main (){
    int tabuleiro[10][10];
    #define TamanhoNavio 3

    for (int INDEX_1 = 0; INDEX_1 < 10; INDEX_1++) {
        for (int INDEX_0 = 0; INDEX_0 < 10; INDEX_0++) {
            tabuleiro[INDEX_1][INDEX_0] = 0; // Atribui 0 (água) a todos os pontos
        }
    }

    for (int Navio1 = 1, i = 1; Navio1 <= TamanhoNavio; Navio1++){
        tabuleiro[Navio1][i] = 3; //ele começa na linha 2 e vai somando até ficar 4 - Vertical
    }

    for (int Navio2_X = 1, i = 8; Navio2_X <= TamanhoNavio; Navio2_X++){
        tabuleiro[i][Navio2_X] = 3; //ele começa na coluna 2 e vai somando até fica 4 - Horizontal
    }

    for (int Navio3 = 1, i = 5; Navio3 <= TamanhoNavio; Navio3++){
        tabuleiro[Navio3+i][Navio3+i] = 3; //ele começa na linha/coluna 7 e vai somando até navio3=3
    }

    for (int Navio4 = 1, i = 5, j = 0; Navio4 <= TamanhoNavio; Navio4++){
        tabuleiro[Navio4][Navio4+i-j] = 3; //linha 2
        j = j + 2; /* vai subtraindo 1 da coluna, já que normalmente ela vai somando 1 (navio4++) e aqui estamos
        subtraindo 2 (1 - 2= -1) */
    }
// tabuleiro [LINHA][COLUNA]


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
            printf("%d  ", tabuleiro[INDEX_1][INDEX_0]);
        };
        printf("\n");

    };
}