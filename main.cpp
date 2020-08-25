/*inicio do jogo*/
#define TAM 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#include "Pilha_LE.h" //Biblioteca que contém as funções referentes a pilha.
#include "estrutura.h"
#include "controles.h"

//Criei esse main só para testar as funções criadas.
int main() {
    //Def de variaveis globais
    int tab[TAM][TAM] = {0};
    int pont = 0;
    int recorde = 0; 
    char tecla1[2];
    int tecla;
    no *L;
    
    srand(time(NULL)); //Comando para a pseudoaleatoriedade

    inicializa_tabuleiro(tab, &pont);
    imprime_tabuleiro (tab, recorde, &pont);
    do {
        gets(tecla1);
        tecla = atoi(tecla1);
        if (movimentos(tab, tecla, &pont, &L) == 1){
            num_aleatorio(tab);
        }
        //system("cls");
        imprime_tabuleiro (tab, recorde, &pont);
    }while ((tecla != 9) && (perde(tab) != 1));
    return 0;
}
