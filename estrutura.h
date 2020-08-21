/*funçoes para:
	tabuleiro do jogo
	geração de peças
	combinação de peças
*/
void imprime_tabuleiro (int tab[4][4], int recorde, int *pont);
void dois_aleatorio(int tab[4][4]);
void num_aleatorio(int tab[4][4]);
int perde (int tab[4][4]);
void inicializa_tabuleiro(int tab[4][4], int *pont);

//Função que posiciona o cursor de acordo com coordenadas (X,Y).
//Obs: Por enquanto não foi usada.
void gotoxy( int column, int line ) {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
// gotoxy(33,9);

//Função que imprime o tabuleiro juntamente com os pontos, a melhor pontuação e mostra a opção de novo jogo (pressionando a tecla N).
// Obs: ainda falta criar uma função para mostrar a melhor pontuação e uma que associe a tecla N à função inicializa_tabuleiro(tab, &pont).
void imprime_tabuleiro (int tab[4][4], int recorde, int *pont) {
    int i, j;
    printf("\n");
    printf("| RECORDE: %d         |\n", recorde);
    printf("| PONTUA%c%cO: %d       |\n", 128, 199 , *pont); 
    printf("| NOVO JOGO - N      |\n"); 
    printf("\n");
    
    for (i = 0; i < 4; i++) {
		printf("|");
		for (j = 0; j < 4; j++){
			if (tab[i][j])
                printf("%*d |", 4, tab[i][j]); 
            else
                printf("     |");
        }
        printf("\n");
	}
    printf("\n"); 

}

//Função que adiciona dois números aleatórios no início do jogo, podendo ser 2 ou 4.
void dois_aleatorio(int tab[4][4]){ 
    int i, j, aux = 0;
    while(aux < 2) {
        i=rand()%4;
	    j=rand()%4;
        if (tab[i][j] == 0) {
            tab[i][j] = (rand() & 3) ? 2 : 4; //Possibilidades: 60% de gerar o número 2 e 40% o número 4.   
            aux++;
        } 
    }   
}

//Função que adiciona um número aleatório após a moviventação das peças do jogo a cada rodada, podendo ser 2 ou 4.
void num_aleatorio(int tab[4][4]){ 
    int i, j, aux = 0;
    while(aux < 1) {
        i=rand()%4;
	    j=rand()%4;
        if (tab[i][j] == 0) {
            tab[i][j] = (rand() & 3) ? 2 : 4; //Possibilidades: 60% de gerar o número 2 e 40% o número 4.         
            aux++;
        } 
    }   
}

//Função que percorre todo o tabuleiro procurando espaços, se não houver nenhum espaço, o jogador perdeu.
int perde (int tab[4][4]) {
    int i, j, cont = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (tab[i][j] != 0) {
                //Verifica se ainda pode ocorrer algum movimento somando valores.
                if ((tab[i][j] == tab[i][j+1]) || (tab[i][j] == tab[i+1][j]) || (tab[i][j] == tab[i][j-1]) || (tab[i][j] == tab[i-1][j]))
                    cont--; 
                else 
                    cont++;
            }        
        }
    }
    if (cont == 16) //Significa que não há espaços para adicionar mais blocos no tabuleiro e não pode ocorrer nenhum movimento.(Fim de Jogo)
        return 1;
    else 
        return 0; //Ainda há espaço no tabuleiro para adicionar mais blocos e é possível movimentar algum bloco.
}

//Função que zera o tabuleiro e o valor da pontuação.
void inicializa_tabuleiro(int tab[4][4], int *pont) {
    int i, j;
    *pont = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            tab[i][j] = 0;
        }
    }
    dois_aleatorio(tab); //Inicia o jogo com dois blocos adicionados aleatoriamente.
}

