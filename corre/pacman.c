#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pacman.h"
#include "mapa.h"

MAPA m; POSICAO pers;

int main() {
    le_mapa(&m);
    encontra_mapa(&m, &pers, PERSONAGEM);
    do {
        imprime_mapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);
        inimigos();
    } while(!acabou());
    system("cls");
    printf("perdeu otario");
    libera_mapa(&m);
fflush(stdin);
getchar();
}

int tecla_movimento(int dir) {
    if(dir!='w'&&
       dir!='a'&&
       dir!='s'&&
       dir!='d') {
            return 0;
       }
    return 1;
}

void move(char dir) {
    if(!tecla_movimento(dir)) { //checa se o jogador apertou aluma tecla que nao é uma e movimento valido
        return; //return em void = matar a função
    }
    
    int prox_x = pers.x;
    int prox_y = pers.y;

    switch(dir) { 
        case CIMA:
            prox_x--;
            break;
        case ESQUERDA:
            prox_y--;
            break;
        case BAIXO:
            prox_x++;
            break;
        case DIREITA:
            prox_y++;
            break;
    }

    if(!posicao_permitida(&m, INIMIGO, prox_x, prox_y)) {
        return;
    }

    andar(&m, pers.x, pers.y, prox_x, prox_y);
    pers.x = prox_x;
    pers.y = prox_y;
}

int acabou() {
    POSICAO pos;
    int tavivo = encontra_mapa(&m, &pos, PERSONAGEM);
    
    return !tavivo;
}

void inimigos() {
    MAPA copia;

    copia_mapa(&copia, &m);
    for(int i=0; i<copia.linhas; i++) {
        for(int j=0; j<copia.colunas; j++) {
            if(copia.matriz[i][j] == INIMIGO) {

                int dest_x, dest_y;

                int encontrou = dest_inimigo(i, j, &dest_x, &dest_y);

                if(encontrou) {
                    andar(&m, i, j, dest_x, dest_y);
                }
            }
        }
    }
    libera_mapa(&copia);
}

int dest_inimigo(int pos_x, int pos_y, int* dest_x, int* dest_y) {

    int opcoes[4][2] = {
        {pos_x, pos_y+1},
        {pos_x+1, pos_y},
        {pos_x, pos_y-1},
        {pos_x-1, pos_y}
    };

    srand(time(0));
    for (int i=0; i<5; i++) {
        int posicao = rand() % 4;

        if(posicao_permitida(&m, INIMIGO, opcoes[posicao][0], opcoes[posicao][1])) {
            *dest_x = opcoes[posicao][0];
            *dest_y = opcoes[posicao][1];

            return 1;
        }

    }
    return 0;
}