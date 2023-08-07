#include <stdio.h>
#include <string.h>

int main() {
    char psecreta[15];
    sprintf(psecreta, "CELULAR"); //sprintf define o conteudo de um vetor/array de chars

    int acertou = 0; int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    do {

        for(int i=0; i<strlen(psecreta); i++) {
            
            int achou = 0;
            for(int j=0; j<tentativas; j++) {
                if(chutes[j] == psecreta[i]) {
                    achou = 1;
                    break;
                }
            }
            if(achou) { //nao é necessario colocar '== 1' pois se entende que achou é booleana(1 ou 0)
                printf("%c ", psecreta[i]);
            }
            else {
            printf("_ ");
            }
        }
        printf("\n");
        char chute;
        scanf(" %c", &chute); // " %c", o espaço antes do %c garante que o 'enter' não seja lido como char

        chutes[tentativas] = chute; //chute do jogador na posição tentativa = chute do jogador
        tentativas++;

    }   while(!acertou && !enforcou); // -> ! indica negação, nesse caso, enquanto(nao acertou e nao enforcou)
}