#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

#include "pacman.h"
#include "mapa.h"
#include "ui.h"

MAPA m; POSICAO pers; int tem_espada = 0; int tem_municao = 0; int tem_bomba = 1;

int main() { setlocale(LC_ALL, "Portuguese_Brazil");

    le_mapa(&m);
    encontra_mapa(&m, &pers, PERSONAGEM);
    do {
        system("cls");
        printf("***ITENS***\n");
        printf("ESPADA: %d |MUNIÇÃO: %d |BOMBAS: %d\n", tem_espada, tem_municao, tem_bomba);

        imprime_mapa(&m);

        char comando;
        fflush(stdin);
        scanf(" %c", &comando);
        move(comando);
        if(comando == EXPLODIR && tem_bomba > 0) {
            usar_bomba(pers.x, pers.y, 3);
            tem_bomba--;
        }

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

    if(ehpersonagem(&m, BOMBA, prox_x, prox_y)) {
        tem_bomba += 1;
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

void usar_bomba() {
    usar_bomba2(pers.x, pers.y, 0, 1, 3);
    usar_bomba2(pers.x, pers.y, 0, -1, 3);
    usar_bomba2(pers.x, pers.y, 1, 0, 3);
    usar_bomba2(pers.x, pers.y, -1, 0, 3);
}

void usar_bomba2(int x, int y, int somax, int somay, int qtd) {
    if(qtd == 0) return;

    int novox = x+somax;
    int novoy = y+somay;

    if(!posicao_valida(&m, novox, novoy)) {
        return;
    }
    if(ehparede(&m, novox, novoy)) {
        return;
    }

    m.matriz[novox][novoy] = VAZIO;
    usar_bomba2(novox, novoy, somax, somay, qtd-1);
}



//programar a pistola, crie um projetil que navega por espaços vazios até atingir um inimigo ou uma parede

//função recursiva, ultilizar para bombas ou em casos similares(como a pistola que vou fazer)


/*
void usar_espada() {
    //MessageBoxW(NULL, L"shiiiiiiiiin", L"Usou a espada", MB_OK | MB_ICONINFORMATION);
    Beep(1000, 150);
    for(int i=1; i<=1; i++) {
        if(posicao_valida(&m, pers.x, pers.y+i) || posicao_valida(&m, pers.x, pers.y-i)) {
            if(ehparede(&m, pers.x, pers.y+i) || ehparede(&m, pers.x, pers.y-i)) {
                break;
            }
            m.matriz[pers.x][pers.y+i] = VAZIO; m.matriz[pers.x][pers.y-i] = VAZIO;
        }
    }
}
*/