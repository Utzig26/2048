/*funçoes para:
	tabuleiro do jogo
	geração de peças
	combinação de peças
*/
#define NUM_INI 2

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
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
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

int verifica_vazio (int tab[4][4]){ // retorna 1 se tiver algum espaço, ou retorna 0 se estiver cheio
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tab[i][j] == 0) 
                return 1;
        }
    }
    return 0;
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
int perde (int tab[TAM][TAM]) {
    int cont = 0;
    if (!verifica_vazio(tab)){ // se tiver espaço livre ele ignora
        for (int i = 1; i <= (TAM/2) ; i++) {
            for (int j = 0; j < TAM; j++) {
                if ((tab[i][j] == tab[i+1][j]) || (tab[i][j] == tab[i-1][j])) //Verifica se ainda pode ocorrer algum movimento somando valores.
                    cont++;    
            }
        }
        for (int j = 1; j <= (TAM/2); j++) {
            for (int i = 0; i < TAM ; i++) {
                if ((tab[i][j] == tab[i][j+1]) || (tab[i][j] == tab[i][j-1])) //Verifica se ainda pode ocorrer algum movimento somando valores.
                    cont++;   
            }
        }
        if (cont == 0) //Significa que não há espaços para adicionar mais blocos no tabuleiro e não pode ocorrer nenhum movimento.(Fim de Jogo)
            return 1;
        
        return 0; //Ainda há espaço no tabuleiro para adicionar mais blocos e é possível movimentar algum bloco.
    }
}

//Função que zera o tabuleiro e o valor da pontuação.
void inicializa_tabuleiro(int tab[TAM][TAM], int *pont) {
    *pont = 0;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tab[i][j] = 0;
        }
    }
    for(int i = 0; i < NUM_INI; i++){ //geração dos primeiros numeros aleátorios
        num_aleatorio(tab);
    }
}

