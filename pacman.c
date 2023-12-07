#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

char** mapa;
int linhas;
int colunas;

int main() {
    le_mapa();

        imprime_mapa();

    libera_mapa();
}

void le_mapa() {
    FILE*f;
    f = fopen("../mapa.txt", "r");
    if(f == NULL) {
        printf("Erro ao ler mapa\n");
        exit(1);
    }

    fscanf(f, "%d %d", &linhas, &colunas); //fscanf le os conteudos do arquivo f, no caso, mapa.txt

    aloca_mapa();

    for(int i=0; i<5; i++) {
        fscanf(f, "%s", mapa[i]);
    }
    fclose(f);
}

void aloca_mapa() { /*DEFINE DINAMICAMENTE O TAMANHO DO MAPA*/
    mapa = malloc(sizeof(char*) * linhas); //aloca dinamicamente as linhas
    for(int i=0; i<linhas; i++) {
        mapa[i] = malloc(sizeof(char) * colunas+1); //aloca dinamicamente um vetor coluna pra cada linha
    }
}

void libera_mapa() {
    for(int i=0; i<linhas; i++) {
        free(mapa[i]);
    }
    free(mapa);
}

void imprime_mapa() {
    for(int i=0; i<linhas; i++) {
        printf("%s\n", mapa[i]);//ao imprimir apenas um vetor da matriz, ele me devolve toda a linha, nao somente um caracter especifico
    }
}