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

//Def de variaveis globais
int tab[TAM][TAM] = {0};
int pont = 0;
int recorde = 0; //Ainda falta uma função para arquivar e selecionar a melhor pontuação.
char tecla = 0;
char resp = 0;
no *L;


void jogar() {
    int i, j;
    inicializa_tabuleiro(tab, &pont);
    imprime_tabuleiro (tab, recorde, &pont);
    do {
        tecla = getch();
        if ((tecla == 'N') || (tecla == 'n')) 
            inicializa_tabuleiro(tab, &pont);
        if (movimentos(tab,tecla, &pont, &L) == 1) 
            num_aleatorio(tab);
        system("cls");
        imprime_tabuleiro (tab, recorde, &pont);
        for (i = 0; i < TAM; i++) {
            for (j = 0; j < TAM; j++) {
                if (tab[i][j] == 2048) {
                    printf ("\nParab%cns! Voc%c ganhou!\n", 130, 136);
                    printf("PONTUA%c%cO: %d\n", 128, 199 , pont); 
                    printf("Gostaria de jogar novamente? (S / N)\n");
                    resp = getch();
                    if ((resp == 's') || (resp == 'S'))
                        jogar();
                }
            }
        }
    } while ((tecla != 27) && (perde(tab) != 1)); 
    if (perde(tab) == 1) {
        printf ("\nVoc%c perdeu!\n", 136);
        printf("PONTUA%c%cO: %d\n", 128, 199 , pont); 
        printf("Gostaria de jogar novamente? (S / N)\n");
        resp = getch();
        if ((resp == 's') || (resp == 'S')) {
            system("cls");
            jogar();
        }
    } 
}

int main() {  
    srand(time(NULL)); //Comando para a pseudoaleatoriedade
    jogar();
    system("cls");
    return 0;
}
