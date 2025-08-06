#include <stdio.h>
    #define TamanhoNavio 3
    #define LinhaPODER 3
    #define ColunaPODER 3
    #define ColunaPODERCONE 5
    #define TABULEIRO_LINHA 10
    #define TABULEIRO_COLUNA 10
    #define LinhaPODER_octa 5
    #define ColunaPODER_octa 5


int main (){
    int tabuleiro[TABULEIRO_LINHA][TABULEIRO_COLUNA];
    int PoderCone[LinhaPODER][ColunaPODERCONE];
    int PoderCruz[LinhaPODER][ColunaPODER];
    int PoderOctaedro[LinhaPODER_octa][ColunaPODER_octa];

    for (int i = 0; i < TABULEIRO_LINHA; i++) {
        for (int j = 0; j < TABULEIRO_COLUNA; j++) {
            tabuleiro[i][j] = 0; // Atribui 0 (água) a todos os pontos
        }
    }

// CONFIGURAR E ADICIONAR A TABELA CONE AO TABULEIRO
    for (int i = 0; i < LinhaPODER; i++){ //todas as posições virar 0
        for (int j = 0; j < ColunaPODERCONE; j++){
            PoderCone[i][j] = 0;
        }
    }

for (int i = 0; i < LinhaPODER; i++) { //controla as linhas
    int centro = ColunaPODERCONE/2; // int centro = 5/2 = 2 (meio da matriz sendo um inteiro)
    for (int j = 0; j < ColunaPODERCONE; j++) { //controla as colunas
        if (j >= centro - i && j <= centro + i) { //se j ser >= que [2,3,4| 1,2,3,4| all] e <= que [2| 0,1,2,3| all] 
            PoderCone[i][j] = 5; //então matriz[i][j] = 5
        } else {
            PoderCone[i][j] = 0;
        }
    }
}

    int linhaInicial = 2;
    int colunaInicial = 2;
    for (int i = 0; i < LinhaPODER; i++) { //passa pelas 3 linhas
        for (int j = 0; j < ColunaPODERCONE; j++) { //passa pelas 5 colunas
            int linhaTab = linhaInicial + i; //2 à 4
            int colunaTab = colunaInicial + j; //2 à 6

            if (linhaTab < 10 && colunaTab < 10) { //passa por cada linha/coluna da Matriz principal. Começa: [2][2]
                if (PoderCone[i][j] == 5) {
                    tabuleiro[linhaTab][colunaTab] = 5; //se for 5 ele muda na matriz principal
                }
            }
        }
    }

// CONFIGURAR E ADICIONAR A TABELA Cruz AO TABULEIRO
    for (int i = 0; i < LinhaPODER; i++){ //tabela em branco (0)
        for (int j = 0; j < ColunaPODER; j++){
            PoderCruz[i][j] = 0;
        }
    }
    
    for (int i = 0; i < LinhaPODER; i++){
        for (int j = 0; j < ColunaPODER; j++){
            if (i == 1 || j == 1){ //pego todas as posições centrais -> se i tá igual ao centro ou j = centro
                PoderCruz[i][j] = 5;
            }
        }
    }

    int linhaCruz = 6;  //LINHA INICIAL
    int colunaCruz = 6; //COLUNA INICIAL
    for (int i = 0; i < LinhaPODER; i++) { //CONTROLA AS LINHAS
        for (int j = 0; j < ColunaPODER; j++) { //CONTROLA AS COLUNAS
            int linhaTab = linhaCruz + i; //VAI DE 6 À 8  -  PEGA TODAS AS POSIÇÕES DA TABELA DA CRUZ
            int colunaTab = colunaCruz + j; // VAI DE 6 À 8  - IDEM

            if (linhaTab < 10 && colunaTab < 10) {
                if (PoderCone[i][j] == 5) {  //VERIFICA TODA A ÁREA DA TABELA DO CONE, SE FOR IGUAL Á 5 ELE PÕE
                    tabuleiro[linhaTab][colunaTab] = 5; //NO TABULEIRO
                }
            }
        }
    }

// CONFIGURAR E ADICIONAR A TABELA Octaedro AO TABULEIRO
for (int i = 0; i < LinhaPODER_octa; i++){
    for(int j = 0; j < ColunaPODER_octa; j++){
        PoderOctaedro[i][j] = 0;
    }
}

for (int i = 0; i < LinhaPODER_octa; i++){
    for(int j = 0; j < ColunaPODER_octa; j++){
        if ((i == 0 || i == 4) && j == 2){
            PoderOctaedro[i][j] = 5;
        }
        if ((i == 1 || i == 3) && j >= 1 && j <= 3){
            PoderOctaedro[i][j] = 5;
        }
        if (i == 2 && j >= 0 && j <= 4){
            PoderOctaedro[i][j] = 5;
        }
    }
}

for (int i = 0; i < LinhaPODER_octa; i++){
    int LINHAINICIAL_octa = 5, COLUNAINICIAL_octa = 1;
    for(int j = 0; j < ColunaPODER_octa; j++){
        int TAB_inicialLINHA = LINHAINICIAL_octa + i;
        int TAB_inicialCOLUNA = COLUNAINICIAL_octa + j;

        if (TAB_inicialLINHA < 10 && TAB_inicialCOLUNA < 10){
            if (PoderOctaedro[i][j] == 5){
                tabuleiro[TAB_inicialLINHA][TAB_inicialCOLUNA] = 5;
            }
        }
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