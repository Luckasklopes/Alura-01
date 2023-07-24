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

	//for que executa o jogo nas dificuldades 1 2 3

		for(int i=0; i<ntentativas; i++) {
			printf("tentativa %d de %d\n", tentativas, ntentativas);
			printf("Qual o seu chute?");
			int chute;
				fflush(stdin);
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
			else { //else que checa se o chute é maior/menor que o nsecreto
				if (chute > nsecreto) {
					printf("%d e maior que o numero secreto\n", chute);
				}
				if (chute < nsecreto) {
					printf("%d e menor que o numero secreto\n", chute);
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
			printf("voce acertou em %d tentativas e fez %.1f pontos\n", tentativas, pontos);
			printf("Que tal jogar novamente?\n");
		}
		else {
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

void titulo() { //imagem/texto que aparecem ao abrir o jogo
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