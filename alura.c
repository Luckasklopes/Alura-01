#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void titulo();
int qntvidas(int num);
int random();


int main() {
	titulo();
	char dnv;
	int ganhou;
	do {
		int nsecreto = random();
		int tentativas = 1;
			printf("em qual dificuldade voce deseja jogar?\n");
			printf("1 - facil\n");
			printf("2 - medio\n");
			printf("3 - dificil\n");
				int dificuldade;
				fflush(stdin);
				scanf("%d", &dificuldade);
				int ntentativas = qntvidas(dificuldade);
		//for que executa o jogo nas dificuldades 1 2 3
		for(int i=0; i<ntentativas; i++) {
			printf("tentativa %d de %d\n", tentativas, ntentativas);
			printf("Qual o seu chute?");
			int chute;
				fflush(stdin);
				scanf("%d", &chute);

			if (chute < 0) {
				printf("voce nao pode chutar numeros negativos\n");
				continue;
			}
			else if (chute == nsecreto) {
				printf("\n");
					ganhou = 1;
					break;
			}
			else { //else que checa se o chute é maior/menor que o nsecreto
				if (chute > nsecreto) {
					printf("%d eh maior que o numero secreto\n\n", chute);
				}
				if (chute < nsecreto) {
					printf("%d eh menor que o numero secreto\n\n", chute);
				}
				tentativas++;
			}
			// ainda nao sei exatamente oq é isso
			/*	
				double subpontos = (chute - nsecreto) * (double)2;
				pontos = abs(pontos) - abs(subpontos);
			*/
	}
	printf("\n");
	printf("\n");
		//detecção de vitória/derrota
		if (ganhou == 1){
			printf("Parabens!! voce ganhou\n");
			tentativas--;
			printf("voce acertou em %d tentativas\n", tentativas);
		}
		else {
			printf("Fim de jogo!\n");
			printf("poxa,voce perdeu\n");
		}
	printf("\n");
	printf("\n");
	printf("que tal jogar novamente? s\\n\n");
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
	numerasso = numerasso % 100;
	return(numerasso);
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