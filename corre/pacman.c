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
    if(dir!='w'&& dir!='a'&& dir!='s'&& dir!='d') {
        return; //return em void = matar a função
    }
    
    int prox_x = pers.x;
    int prox_y = pers.y;

    switch(dir) { 
        case 'w':
            prox_x--;
            break;
        case 'a':
            prox_y--;
            break;
        case 's':
            prox_x++;
            break;
        case 'd':
            prox_y++;
            break;
    }

    if(prox_x>=m.linhas) { //se o proximo movimento for maior que o numero de lihas
        return;
    }
    if(prox_y>=m.colunas) { //se o proximo movimento for maior que o numero de colunas
        return;
    }
    if(m.matriz[prox_x][prox_y] != '.') { //se o proximo movimento for para uma casa diferente de '.'
        return; //mate a função
    }
        m.matriz[prox_x][prox_y] = '@'; //proxima casa vira o personagem
        m.matriz[pers.x][pers.y] = '.'; //casa anterior vira um ponto
        pers.x = prox_x;
        pers.y = prox_y; //atualiza a posição do personagem para a proxima posição
}

int acabou() {
return 0;
}