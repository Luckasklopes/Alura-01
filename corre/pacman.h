#ifndef _PACMAN_H_
#define _PACMAN_H_

#define CIMA     'w'
#define ESQUERDA 'a'
#define BAIXO    's'
#define DIREITA  'd'
#define EXPLODIR 'q'
//#define BATER    'e'
//#define ATIRAR   'c'

void move(char dir);
int tecla_movimento(int dir);
int acabou();
void inimigos();
int dest_inimigo(int pos_x, int pos_y, int* dest_x, int* dest_y);
//void usar_espada();
void usar_bomba();
void usar_bomba2(int x, int y, int somax, int somay, int qtd);

#endif