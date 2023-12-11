#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "forca.h"

/*VARIAVEIS GLOBAIS*/
char psecreta[PTAMANHO];
char chutes[26];
int tentativas = 0;

/*FUNÇÃO MAIN*/
int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    titulo();
    escolhe_palavra();

    do {
        imprime();
        attp(chutes);

    }   while(!acertou() && !enforcou());

    if(acertou()) {
        system("cls");
            printf("  _______      \n");
            printf(" |/      |     \n");
            printf(" |             \n");
            printf(" |             \n");
            printf(" |    \\(^.^)/ \n");
            printf(" |       |     \n");
            printf("_|___   / \\   \n");
        printf("\n\n\n");
        printf("Parabens!! %s era a palavra secreta\n", psecreta);
        printf("Voce descobriu ela em  %d  letras", tentativas);
        printf("\n\n\n");
    }
    if(enforcou()) {
        system("cls");
            printf("  _______      \n");
            printf(" |/      |     \n");
            printf(" |     (x_x)   \n");
            printf(" |      /|\\   \n");
            printf(" |      / \\   \n");
            printf(" |             \n");
            printf("_|___          \n");
        printf("\n\n\n");
        printf("Que pena!  %s  era a palavra secreta\n", psecreta);
        printf("Voce perdeu com  %d  tentativas", tentativas);
        printf("\n\n\n");
    }
fflush(stdin);
getchar();
}


/*CORPO DAS FUNÇÕES*/
void titulo() {                                      //imagem/texto que aparecem ao abrir o jogo
	printf("                                                 ------------------------------------------\n");
	printf("                                                   Seja bem vindo ao meu segundo joguinho  \n");
	printf("                                                 ------------------------------------------\n");
	printf("\n\n");
    printf("  _____________________        _____________________        _____________________        _____________________        _____________________ \n");
    printf(" /                    /|      /                    /|      /                    /|      /                    /|      /                    /|\n");
    printf("/____________________/ |     /____________________/ |     /____________________/ |     /____________________/ |     /____________________/ |\n");
    printf("|                   |  |     |                   |  |     |                   |  |     |                   |  |     |                   |  |\n");
    printf("|                   | /      |      _______      |  |     |      _______      |  |     |                   | /      |      _______      |  |\n");
    printf("|        ___________|/_      |     |  |    |     |  |     |     |  |____|     |  |     |        ___________|/       |     |  |____|     |  |\n");
    printf("|       |             /|     |     |  |    |     |  |     |     | /     |     |  |     |        |  |                |     | /     |     |  |\n");
    printf("|       |___________ / |     |     |  |    |     |  |     |     |/______|     |  |     |        |  |                |     |/______|     |  |\n");
    printf("|                   |  |     |     |  |    |     |  |     |                   | /      |        |  |                |                   |  |\n");
    printf("|                   | /      |     |  |    |     |  |     |       _       ____|/       |        |  |                |      _______      |  |\n");
    printf("|        ___________|/       |     |  |    |     |  |     |      | \\      \\    \\       |        |  |__________      |     |  |    |     |  |\n");
    printf("|       |  |                 |     |  |____|     |  |     |      |  \\      \\    \\      |        | /          /|     |     |  |    |     |  |\n");
    printf("|       |  |                 |     | /     |     |  |     |      |  |\\      \\   /|     |        |/_________ / |     |     |  |    |     |  |\n");
    printf("|       |  |                 |     |/______|     |  |     |      |  | \\      \\ / |     |                   |  |     |     |  |    |     |  |\n");
    printf("|       | /                  |                   | /      |      | /   |      | /      |                   | /      |     | /     |     | / \n");
    printf("|_______|/                   |___________________|/       |______|/    |______|/       |___________________|/       |_____|/      |_____|/  \n");

        printf("pressione qualquer tecla para comecar..:");
        getchar();
    system("cls");
}

void attp(char chutes[26]) {
        char chute;
        scanf(" %c", &chute); // " %c", o espaço antes do %c garante que o 'enter' não seja lido como char

        chutes[tentativas] = chute; //chute do jogador na posição tentativa = chute do jogador
        tentativas++;
}

void imprime() {
    int erros = chutes_errados(); /*( CONDIÇÃO ? VERDADEIRO : FALSO) */

    system("cls");
    printf("  _______            \n");
    printf(" |/      |           \n");
    printf(" |     %c%c%c%c%c    \n", (erros>=1 ? '(' : ' '), (erros>=1 ? 'o' : ' '), (erros>=1 ? '_' : ' '), (erros>=1 ? 'o' : ' '), (erros>=1 ? ')' : ' '));
    printf(" |      %c%c%c       \n", (erros>=3 ? '/' : ' '), (erros>=2 ? '|' : ' '), (erros>=3 ? '\\' : ' '));
    printf(" |      %c %c        \n", (erros>=4 ? '/' : ' '), (erros>=4 ? '\\' : ' '));
    printf(" |                   \n");
    printf("_|___                \n");
    printf("\n\n");

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
    //sprintf(psecreta, "CELULAR"); //sprintf define o conteudo de um vetor/array de chars
    FILE* f;

    f = fopen("../palavras.txt", "r");
    if(f==NULL) {
        printf("Desculpe, banco de dados n�o dispon�vel\n\n");
        exit(1);
    }
    //printf("arquivo aberto com suceso\n");
    
    int qtdpalavras;
    fscanf(f, "%d", &qtdpalavras);
    //printf("numero total de palavras: %d\n", qtdpalavras);

    if (qtdpalavras == 0) {
        printf("Nenhuma palavra dispon�vel no arquivo\n");
        exit(1);
    }


    srand(time(0));
    int aleatorio = rand() % qtdpalavras;

    for(int i=0; i<=aleatorio; i++) {
        if (fscanf(f, "%s", psecreta) != 1) {
            printf("Erro ao ler palavra do arquivo\n");
            exit(1);
        }
    }

    fclose(f);
}

void adiciona_palavra() {
    char quer;

    printf("Voce deseja adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &quer);

    if(quer == 'S' || 's') {
        char novapalavra[PTAMANHO];

        printf("Digite a nova palavra, em letras maiusculas: ");
        scanf("%s", novapalavra);

        FILE* f;

        f = fopen("../palavras.txt", "r+");
        if(f == NULL) {
            printf("Banco de dados de palavras nao disponivel\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET); //função que "procura" a primeira linha do arquivo
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END); //função que procura a ultima linha do arquivo
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
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

int chutes_errados() {
    int erros = 0;
    for(int i=0; i<tentativas; i++) {
        int existe = 0;
        for(int j=0; j<strlen(psecreta); j++) {
            if(chutes[i] == psecreta[j]) {
                existe = 1;
                break;
            }
        }
        if(!existe) {
            erros++;
        }
    }
    return erros;
}

int enforcou() {
    return chutes_errados() >= 5;
}

int acertou() {
    for(int i=0; i<strlen(psecreta); i++) {
        if(!check(psecreta[i])) {
            return 0;
        }
    }
    return 1;
}