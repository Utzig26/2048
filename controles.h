/*funçoes para:
	movimentação das peças
*/
int movimentos (int tab[4][4], int tecla, int *pont);

//CONTROLE DOS BLOCOS
int movimentos (int tab[4][4], int tecla, int *pont) {
    int i, j, aux2, aux, move = 1; 
    if (tecla == 1) {
        //Seta para a esquerda
        for (i = 0; i < 4; i++) {
            aux2 = 0; //A variável aux2 deveria impedir a soma em cadeia, mas não deu certo :(
            for (j = 1; j < 4; j++) { //A coluna j começa no 1, pois se fosse no 0 não teria como ir para a esquerda.
                if (tab[i][j] != 0) { //Verifica se o número nessa posição é diferente de 0 para que haja movimentação.
                    aux = j; //aux é usado para que a variável j (coluna) não seja alterada dentro do loop.
                    for (aux; aux > aux2; aux--) { //Posiciona o número até j = 0 no máximo.
                        if (tab[i][aux-1] == 0) { //Se o número anterior é 0, há o deslocamento.
                            tab[i][aux-1] = tab[i][aux];
                            tab[i][aux] = 0; 
                        }
                        else if (tab[i][aux-1] == tab[i][aux]) { //Se o número anterior é igual, ocorre a soma.
                            tab[i][aux-1] += tab[i][aux-1];
                            tab[i][aux] = 0;
                            (*pont) += 4; //Pontuação recebe 4 unidades a mais, cada vez que dois blocos iguais são unidos.
                            aux2 = aux-1; //aux2 recebe a última posição em que a soma foi realizada, para que impedisse outra soma neste local novamente.
                        }
                    } 
                }
            }
        }
    }
    else if (tecla == 2) {
        //Seta para a direita
        for (i = 0; i < 4; i++) {
            aux2 = 3; //A variável aux2 deveria impedir a soma em cadeia, mas não deu certo :(
            for (j = 2; j >= 0; j--) { //A coluna j começa no 2, pois se fosse no 3 não teria como ir para a direita.
                if (tab[i][j] != 0) { //Verifica se o número nessa posição é diferente de 0 para que haja movimentação.
                    aux = j; //aux é usado para que a variável j (coluna) não seja alterada dentro do loop.
                    for (aux; aux < aux2; aux++) { //Posiciona o número até j = 3 no máximo.
                        if (tab[i][aux+1] == 0) { //Se o número posterior é 0, há o deslocamento.
                            tab[i][aux+1] = tab[i][aux];
                            tab[i][aux] = 0;
                        }
                        else if (tab[i][aux+1] == tab[i][aux]) { //Se o número posterior é igual, ocorre a soma.
                            tab[i][aux+1] += tab[i][aux+1];
                            tab[i][aux] = 0;
                            (*pont) += 4; //Pontuação recebe 4 unidades a mais, cada vez que dois blocos iguais são unidos.
                            aux2 = aux+1; //aux2 recebe a última posição em que a soma foi realizada, para que impedisse outra soma neste local novamente.
                        }
                    }
                }
            }
        }    
    }
    else if (tecla == 3) {
        //Seta para cima
        for (j = 0; j < 4; j++) {
            aux2 = 0; //A variável aux2 deveria impedir a soma em cadeia, mas não deu certo :(
            for (i = 1; i < 4; i++) { //A linha i começa no 1, pois se fosse no 0 não teria como ir para cima.
                if (tab[i][j] != 0) { //Verifica se o número nessa posição é diferente de 0 para que haja movimentação.
                    aux = i; //aux é usado para que a variável i (linha) não seja alterada dentro do loop.
                    for (aux; aux > aux2; aux--) { //Posiciona o número até i = 0 no máximo.
                        if (tab[aux-1][j] == 0) { //Se o número acima é 0, há o deslocamento.
                            tab[aux-1][j] = tab[aux][j];
                            tab[aux][j] = 0;
                        }
                        else if (tab[aux-1][j] == tab[aux][j]) { //Se o número acima é igual, ocorre a soma.
                            tab[aux-1][j] += tab[aux-1][j];
                            tab[aux][j] = 0;
                            (*pont) += 4; //Pontuação recebe 4 unidades a mais, cada vez que dois blocos iguais são unidos.
                            aux2 = aux-1; //aux2 recebe a última posição em que a soma foi realizada, para que impedisse outra soma neste local novamente.
                        }
                    }
                }
            }
        }    
    }
    else if (tecla == 4) {
        //Seta para baixo
        for (j = 0; j < 4; j++) {
            aux2 = 3; //A variável aux2 deveria impedir a soma em cadeia, mas não deu certo :(
            for (i = 2; i >= 0; i--) { //A linha i começa no 2, pois se fosse no 3 não teria como ir para baixo.
                if (tab[i][j] != 0) { //Verifica se o número nessa posição é diferente de 0 para que haja movimentação.
                    aux = i; //aux é usado para que a variável i (linha) não seja alterada dentro do loop.
                    for (aux; aux < aux2; aux++) {  //Posiciona o número até i = 3 no máximo.
                        if (tab[aux+1][j] == 0) { //Se o número abaixo é 0, há o deslocamento.
                            tab[aux+1][j] = tab[aux][j];
                            tab[aux][j] = 0;
                        }
                        else if (tab[aux+1][j] == tab[aux][j]) { //Se o número abaixo é igual, ocorre a soma.
                            tab[aux+1][j] += tab[aux+1][j];
                            tab[aux][j] = 0;
                            (*pont) += 4; //Pontuação recebe 4 unidades a mais, cada vez que dois blocos iguais são unidos.
                            aux2 = aux+1; //aux2 recebe a última posição em que a soma foi realizada, para que impedisse outra soma neste local novamente.
                        }
                    }
                }
            }
        }    
    }
    else if ((tecla != 1) && (tecla != 2) && (tecla != 3) && (tecla != 4)) 
        move = 0;
    if (move == 1) 
        return 1;
    else 
        return 0;    
}
