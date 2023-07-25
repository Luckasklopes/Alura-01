#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void titulo();
void vitoria(int ganhou);
int qntvidas(int num);
int random();
int attp(int chute, int nsecreto);

int main() {
	titulo();
	char dnv;
	do {
			int nsecreto = random(); int tentativas = 1; int ganhou; int chute; int dificuldade; //declração de algumas variaveis
		//sistema de escolha de modo de jogo
		printf("em qual modo deseja jogar?\n");
		printf("0 - normal\n");
		printf("1 - infinito\n");
			int modo;
			fflush(stdin);
			scanf("%d", &modo);
		switch(modo) {
			case 0: //modo normal
				printf("em qual dificuldade voce deseja jogar?\n");
				printf("1 - facil\n");
				printf("2 - medio\n");
				printf("3 - dificil\n");
					fflush(stdin);
					scanf("%d", &dificuldade);
				int ntentativas = qntvidas(dificuldade);
				for(int i=0; i<ntentativas; i++) { 		//for que executa o jogo nas dificuldades 1 2 3
					printf("tentativa %d de %d\n", tentativas, ntentativas);
					printf("Qual o seu chute? -> ");
						fflush(stdin);
						scanf("%d", &chute);
					ganhou = attp(chute, nsecreto);
					if(ganhou == 1) {
					break;
					}
				}
				break;
			case 1: //modo infinito









				break;
			default:
				printf("escolha um modo de jogo valido");
				continue;
		}

	printf("\n\n");
		vitoria(ganhou);
	printf("\n\n");
	printf("que tal jogar novamente? s/n\n");
		fflush(stdin);
		scanf("%c", &dnv);
	} while(dnv == 's');
}	

int qntvidas(int num) {                              //função para definir a quantidade de vidas
	int vidas;
	switch(num) {
		case 1:
			vidas = 15;
			break;
		case 2:
			vidas = 10;
			break;
		case 3:
			vidas = 5;
			break;
	}
	return(vidas);
}

int random() {                                       //função para gerar o numero aleatorio
	int segundos = time(0);
	srand(segundos);
	int numerasso = rand();
	return(numerasso%100);
}

int attp(int chute, int nsecreto) {                  //função para checar o acerto do chute
	int ganhou;
	if (chute < 0) {
		printf("voce nao pode chutar numeros negativos\n");
	}
	else if (chute == nsecreto) {
		ganhou = 1;
	}
	else { //else que checa se o chute é maior/menor que o nsecreto
		if (chute > nsecreto) {
			printf("%d eh maior que o numero secreto\n\n", chute);
		}
		if (chute < nsecreto) {
			printf("%d eh menor que o numero secreto\n\n", chute);
		}
	}
	return(ganhou);
}

void vitoria(int ganhou) {                           //função para detectar vitória/derrota
	if (ganhou == 1){ //detecção de vitória/derrota
		printf("Parabens!! voce ganhou\n");	
		//printf("voce acertou em %d tentativas\n");
	}
	else {
		printf("Fim de jogo!\n");
		printf("poxa,voce perdeu\n");
	}
}

void titulo() {                                      //imagem/texto que aparecem ao abrir o jogo
	printf("                      -----------------------------------------\n");
	printf("                       Seja bem vindo ao meu primeiro joguinho \n");
	printf("                      -----------------------------------------\n");
	printf("\n\n\n\n");
	printf("			        _____                   /|\n");
	printf("			        |   \\      ____        / |\n");
	printf("			  __    |    \\    /\\   |      /  ;\n");
	printf("			 /\\  \\  |     \\  /  \\  |     /  ; \n");
	printf("			/,'\\  \\ |      \\/  : \\ |    /   ; \n");
	printf("			~  ;   \\|      /   :  \\|   /   ;  \n");
	printf("			   |    \\     /   :'  |   /    ;  \n");
	printf("			   |     \\   /    :   |  /    ;   \n");
	printf("			   |      \\ /    :'   | /     ;   \n");
	printf("			   |       /     :    |/     ;    \n");
	printf("			   |      /     :'    |      ;    \n");
	printf("			    \\    /      :     |     ;     \n");
	printf("			     \\  /      :'     |     ;     \n");
	printf("			      \\       :'      |    ;      \n");
	printf("			       \\______:_______|___;       \n");
	printf("\n\n\n");

}