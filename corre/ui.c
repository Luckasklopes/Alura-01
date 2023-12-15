#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include "ui.h"

char draw_inimigo[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char draw_parede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char draw_personagem[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char draw_bomba[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char draw_vazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

char draw_erro[4][7] = {
    {"XXXXXX"},
    {"XXXXXX"},
    {"XXXXXX"},
    {"XXXXXX"}
};


void imprime_arte(char pixelart[4][7], int p) {
    printf("%s", pixelart[p]);
}

void imprime_mapa(MAPA* m) {
    //system("cls");
    for(int i=0; i<m->linhas; i++) {
        for(int p=0; p<4; p++) { //p é a altura das pixel arts
            for (int j=0; j<m->colunas; j++) {
                switch(m->matriz[i][j]) {
                    case INIMIGO:
                        imprime_arte(draw_inimigo, p);
                        break;
                    case PERSONAGEM:
                        imprime_arte(draw_personagem, p);
                        break;
                    case BOMBA:
                        imprime_arte(draw_bomba, p);
                        break;
                    case VAZIO:
                        imprime_arte(draw_vazio, p);
                        break;
                    case PAREDE_HORIZONTAL:
                    case PAREDE_VERTICAL:
                        imprime_arte(draw_parede, p);
                        break;
                    default:
                        imprime_arte(draw_erro, p);
                        break;
                }
            }
        printf("\n");
        }
        //printf("%s\n", m->matriz[i]);//ao imprimir apenas um vetor da matriz, ele me devolve toda a linha, nao somente um caracter especifico
    }
}