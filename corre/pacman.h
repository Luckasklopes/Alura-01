#define CIMA     'w'
#define ESQUERDA 'a'
#define BAIXO    's'
#define DIREITA  'd'

void move(char dir);
int tecla_movimento(int dir);
int acabou();
void inimigos();
int dest_inimigo(int pos_x, int pos_y, int* dest_x, int* dest_y);