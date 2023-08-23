#include <stdio.h>
#include <string.h>

void titulo();
void attp(char chutes[26], int *ptent);

int main() {
    titulo();
    char psecreta[15];
    sprintf(psecreta, "CELULAR"); //sprintf define o conteudo de um vetor/array de chars

    int acertou = 0; int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    do {

        for(int i=0; i<strlen(psecreta); i++) { // for que contem o sistema de acertou ou erro do jogo
            
            int achou = 0;
            for(int j=0; j<tentativas; j++) { //for que checa se o chute foi correto ou nao
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
        attp(chutes, &tentativas);
    }   while(!acertou && !enforcou); // -> ! indica negação, nesse caso, enquanto(nao acertou e nao enforcou)
}

void titulo() {                                      //imagem/texto que aparecem ao abrir o jogo
	printf("                      -----------------------------------------\n");
	printf("                       Seja bem vindo ao meu segundo joguinho \n");
	printf("                      -----------------------------------------\n");
	printf("\n\n\n\n");
    printf("                                                       _________________________   \n");
    printf("                  /\\\\      _____          _____       |   |     |     |    | |  \\ \n");
    printf("    ,-----,      /  \\\\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ \n");
    printf(",--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\ \n");
    printf("==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'\n");  
    printf("````````````````````````````````````````````````````````````````````````````````````\n");
        printf("pressione qualquer tecla para comecar..:");
        getchar();
}

void attp(char chutes[26], int *ptent) {
        char chute;
        scanf(" %c", &chute); // " %c", o espaço antes do %c garante que o 'enter' não seja lido como char

        chutes[(*ptent)] = chute; //chute do jogador na posição tentativa = chute do jogador
        (*ptent)++;
}