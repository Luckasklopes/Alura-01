
#define PTAMANHO 20

/*VARIAVEIS GLOBAIS*/
char psecreta[PTAMANHO];
char chutes[26];
int tentativas = 0;

/*FUNÇÕES*/
void titulo();
void attp(char chutes[26]);
void imprime();
void escolhe_palavra();
void adiciona_palavra();
int check(char letra);
int chutes_errados();
int enforcou();
int acertou();
void vitoria();
void derrota();