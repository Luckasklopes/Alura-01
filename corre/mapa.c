#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void le_mapa(MAPA* m) {
    FILE*f;
    f = fopen("../mapa.txt", "r");
    if(f == NULL) {
        printf("Erro ao ler mapa\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(m->linhas), &(m->colunas)); //fscanf le os conteudos do arquivo f, no caso, mapa.txt

    aloca_mapa(m);

    for(int i=0; i<5; i++) {
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose(f);
}

void aloca_mapa(MAPA* m) { /*DEFINE DINAMICAMENTE O TAMANHO DO MAPA*/
    m->matriz = malloc(sizeof(char*) * m->linhas); //aloca dinamicamente as linhas
    for(int i=0; i<m->linhas; i++) {
        m->matriz[i] = malloc(sizeof(char) * m->colunas+1); //aloca dinamicamente um vetor coluna pra cada linha
    }
}

void libera_mapa(MAPA* m) {
    for(int i=0; i<m->linhas; i++) {
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void imprime_mapa(MAPA* m) {
    system("cls");
    for(int i=0; i<m->linhas; i++) {
        printf("%s\n", m->matriz[i]);//ao imprimir apenas um vetor da matriz, ele me devolve toda a linha, nao somente um caracter especifico
    }
}

void encontra_mapa(MAPA* m, POSICAO* p, char c) {
    for(int i=0; i<m->linhas; i++) {
        for(int j=0; j<m->colunas; j++) {
            if(m->matriz[i][j] == c) {
               p->y = i; p->x = j;
               break;
            }
        }
    }
}