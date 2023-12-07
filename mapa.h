typedef struct mapa MAPA;
struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

void le_mapa(MAPA* m);
void aloca_mapa(MAPA* m);
void libera_mapa(MAPA* m);
void imprime_mapa(MAPA* m);
