/*inicio do jogo*/

#include "estrutura.h"
#include "controles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "Pilha_LE.h" //Biblioteca que contém as funções referentes a pilha.


//Criei esse main só para testar as funções criadas.
int main() {
    int tab[4][4] = {0};
    int pont = 0;
    int recorde = 0; //Falta criar função para armazenar a melhor pontuação!
    char tecla1[2];
    int tecla;
    no *L;
    inicializa_tabuleiro(tab, &pont);
    do {
        imprime_tabuleiro (tab, recorde, &pont);
        gets(tecla1);
        tecla = atoi(tecla1);
        movimentos(tab, tecla, &pont, &L);
        if (movimentos(tab,tecla, &pont, &L) == 1) 
            num_aleatorio(tab);
        atualiza_soma(tab, tecla, &L);
        //system("cls");
        imprime_tabuleiro (tab, recorde, &pont);
    } while ((tecla != 78) && (perde(tab) != 1)); 
    return 0;
}
