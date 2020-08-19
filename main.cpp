/*inicio do jogo*/

#include "estrutura.h"
#include "controles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

//Criei esse main só para testar as funções criadas.
int main() {
    int tab[4][4] = {0};
    int pont = 0;
    int recorde = 0; //Falta criar função para armazenar a melhor pontuação!
    char tecla1[2];
    int tecla;
    inicializa_tabuleiro(tab, &pont);
    do {
        imprime_tabuleiro (tab, recorde, &pont);
        gets(tecla1);
        tecla = atoi(tecla1);
        movimentos(tab, tecla, &pont);
        if (movimentos(tab,tecla, &pont) == 1) //Se ocorrer movimento dos blocos, um número aleatório é adicionado ao tabuleiro logo após.
            num_aleatorio(tab);
        //system("cls");
        imprime_tabuleiro (tab, recorde, &pont);
    } while ((tecla != 78) && (perde(tab) != 1)); //Enquanto não for digitado o número 78 (era pra ser a tecla N) ou ainda houver espaços no tabuleiro o loop continua.
    return 0;
}

