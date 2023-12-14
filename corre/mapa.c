#include <stdio.h>
#include <stdlib.h>
#include <String.h>
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
    //system("cls");
    for(int i=0; i<m->linhas; i++) {
        printf("%s\n", m->matriz[i]);//ao imprimir apenas um vetor da matriz, ele me devolve toda a linha, nao somente um caracter especifico
    }
}

int encontra_mapa(MAPA* m, POSICAO* p, char c) {
    for(int i=0; i<m->linhas; i++) {
        for(int j=0; j<m->colunas; j++) {
            if(m->matriz[i][j] == c) {
               p->y = i; p->x = j;
               return 1;
            }
        }
    }
    return 0;
}

int posicao_valida(MAPA* m, int x, int y) {
    if(x>=m->linhas) { //se o proximo movimento for maior que o numero de lihas
        return 0;
    }
    if(y>=m->colunas) { //se o proximo movimento for maior que o numero de colunas
        return 0;
    }
    return 1;
}

void andar(MAPA* m, int ant_x, int ant_y, int prox_X, int prox_y) {
    char personagem = m->matriz[ant_x][ant_y];
    m->matriz[prox_X][prox_y] = personagem;
    m->matriz[ant_x][ant_y] = VAZIO;

        /*m.matriz[prox_x][prox_y] = '@'; //proxima casa vira o personagem
        m.matriz[pers.x][pers.y] = '.'; //casa anterior vira um ponto
        pers.x = prox_x;
        pers.y = prox_y; //atualiza a posição do personagem para a proxima posição*/

}

void copia_mapa(MAPA* destino, MAPA* origem) {
    destino->linhas = origem->linhas;
    destino->colunas = origem ->colunas;

    aloca_mapa(destino);
    for(int i=0; i<origem->linhas; i++) {
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

int posicao_vazia(MAPA* m, int prox_x, int prox_y) {
    return m->matriz[prox_x][prox_y] == VAZIO;  //se o proximo movimento for para uma casa diferente de '.'    
}

int posicao_permitida(MAPA* m, char pers, int prox_x, int prox_y) {
    if(posicao_valida(m, prox_x, prox_y) &&
       !ehparede(m, prox_x, prox_y) &&
       !ehpersonagem(m, pers, prox_x, prox_y))
        return 1;
    return 0;
}

int ehparede(MAPA* m, int prox_x, int prox_y) {
    return (m->matriz[prox_x][prox_y] == PAREDE_VERTICAL ||
            m->matriz[prox_x][prox_y] == PAREDE_HORIZONTAL);
}

int ehpersonagem(MAPA* m, char pers, int prox_x, int prox_y) {
    return (m->matriz[prox_x][prox_y] == pers);
}