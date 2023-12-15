#ifndef _MAPA_H_
#define _MAPA_H_

#define PERSONAGEM '@'
#define INIMIGO '#'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define BOMBA 'Q'
//#define ESPADA 'l'
//#define PISTOLA '~'


typedef struct mapa MAPA;
struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};
typedef struct posicao POSICAO;
struct posicao {
    int x;
    int y;
};
int posicao_permitida(MAPA* m, char pers, int prox_x, int prox_y);
    int posicao_valida(MAPA* m, int x, int y);
    int posicao_vazia(MAPA* m, int prox_x, int prox_y);
    int ehparede(MAPA* m, int prox_x, int prox_y);
    int ehpersonagem(MAPA* m, char pers, int prox_x, int prox_y);
void andar(MAPA* m, int ant_x, int ant_y, int prox_X, int prox_y);
void le_mapa(MAPA* m);
void aloca_mapa(MAPA* m);
void libera_mapa(MAPA* m);
int encontra_mapa(MAPA* m, POSICAO* p, char c);
void copia_mapa(MAPA* destino, MAPA* origem);

#endif