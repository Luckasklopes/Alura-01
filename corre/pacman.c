#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

MAPA m; POSICAO pers;

int main() {
    le_mapa(&m);

    do {
        imprime_mapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);
    } while(!acabou());

    libera_mapa(&m);
}



void move(char dir) {
    int x; int y;

    //achar a posição do personagem no mapa
    for(int i=0; i<m.linhas; i++) {
        for(int j=0; j<m.colunas; j++) {
            if(m.matriz[i][j] == '@') {
                y = i; x = j;
                break;
            }
        }
    }

    switch(dir) {
        case 'w':
            m.matriz[y-1][x] = '@';
            break;
        case 'a':
            m.matriz[y][x-1] = '@';
            break;
        case 's':
            m.matriz[y+1][x] = '@';
            break;
        case 'd':
            m.matriz[y][x+1] = '@';
            break;
    }
    m.matriz[y][x] = '.';
}

int acabou() {

return 0;
}