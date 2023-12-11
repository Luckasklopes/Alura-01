#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

MAPA m; POSICAO pers;

int main() {
    le_mapa(&m);
    encontra_mapa(&m, &pers, '@');
    do {
        imprime_mapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);
    } while(!acabou());

    libera_mapa(&m);
}

void move(char dir) {
    m.matriz[pers.y][pers.x] = '.';

    //achar a posição do personagem no mapa

    switch(dir) {
        case 'w':
            m.matriz[pers.y-1][pers.x] = '@';
            pers.y--;
            break;
        case 'a':
            m.matriz[pers.y][pers.x-1] = '@';
            pers.x--;
            break;
        case 's':
            m.matriz[pers.y+1][pers.x] = '@';
            pers.y++;
            break;
        case 'd':
            m.matriz[pers.y][pers.x+1] = '@';
            pers.x++;
            break;
    }
}

int acabou() {
return 0;
}