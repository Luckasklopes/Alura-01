#include <stdio.h>
#include <string.h>

/*VARIAVEIS GLOBAIS*/
char psecreta[15];
char chutes[26];
int tentativas = 0;

/*FUNÇÕES*/
void titulo();
void attp(char chutes[26]);
void imprime();
void escolhe_palavra();
int check(char letra);

int main() {

    titulo();
    escolhe_palavra();

    int acertou = 0; int enforcou = 0;

    do {

        imprime();
        attp(chutes);

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

void attp(char chutes[26]) {
        char chute;
        scanf(" %c", &chute); // " %c", o espaço antes do %c garante que o 'enter' não seja lido como char

        chutes[tentativas] = chute; //chute do jogador na posição tentativa = chute do jogador
        tentativas++;
}

void imprime() {
    for(int i=0; i<strlen(psecreta); i++) { // for que contem o sistema de acertou ou erro do jogo     
        int achou = check(psecreta[i]);
        if(achou) { //nao é necessario colocar '== 1' pois se entende que achou é booleana(1 ou 0)
            printf("%c ", psecreta[i]);
        }
        else {
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhe_palavra() {
    sprintf(psecreta, "CELULAR"); //sprintf define o conteudo de um vetor/array de chars
}

int check(char letra) {
    int achou = 0;
    for(int j=0; j<tentativas; j++) { //for que checa se o chute foi correto ou nao
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}