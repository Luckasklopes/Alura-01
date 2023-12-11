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


void le_mapa(MAPA* m);
void aloca_mapa(MAPA* m);
void libera_mapa(MAPA* m);
void imprime_mapa(MAPA* m);
void encontra_mapa(MAPA* m, POSICAO* p, char c);