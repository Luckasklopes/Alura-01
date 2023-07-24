#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void titulo();

int main() {
	titulo();
	char dnv;
	do {
		int segundos = time(0);
		srand(segundos);
		int numerasso = rand();

		int ntentativas;
		int nsecreto = numerasso % 100;
		int chute;
		int tentativas = 1;
		int ganhou = 0;
		double pontos = 1000;

			printf("em qual dificuldade voce deseja jogar?\n");
			printf("1 - facil\n");
			printf("2 - medio\n");
			printf("3 - dificil\n");
				int dificuldade;
				scanf("%d", &dificuldade);
					switch(dificuldade) {
						case 1:
							ntentativas = 15;
						case 2:
							ntentativas = 10;
						case 3:
							ntentativas = 5;
					}

		for(int i = 1; i<=ntentativas; i++) {
			printf("\n");
			printf("tentativa %d de %d\n", tentativas, ntentativas);
			printf("Qual o seu chute?");
			scanf("%d", &chute);
			printf("seu chute foi %d\n", chute);

			if (chute < 0) {
				printf("voce nao pode chutar numeros negativos, seu animal\n");
				
				continue;
			}
			else if (chute == nsecreto) {
				printf("\n");
					break;
					ganhou = 1;

			}
			else {
				int maior = chute > nsecreto;
				if (maior) {
					printf("%d e maior que o numero secreto\n", chute);
				}

				int menor = chute < nsecreto;
				if (menor) {
					printf("%d e menor que o numero secreto\n", chute);
				}

				tentativas = tentativas + 1;
			}
					double subpontos = (chute - nsecreto) * (double)2;
			pontos = abs(pontos) - abs(subpontos);

	}

	printf("\n");
	printf("\n");
		if (ganhou == 1){
			printf("Parabens!! voce ganhou\n");
			tentativas--;
			printf("voce acertou em %d tentativas e fez %.1f pontos\n", tentativas, pontos);
			printf("Que tal jogar novamente?\n");
		}
		else if(ganhou != 1) {
				printf("Fim de jogo!\n");
				printf("poxa,voce perdeu\n");
		}

	printf("\n");
	printf("\n");
	printf("deseja jogar novamente? s\\n\n");
		fflush(stdin);
		scanf("%c", &dnv);
	} while(dnv == 's');
}	

void titulo() {
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