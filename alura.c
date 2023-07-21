#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main() {
setlocale(LC_ALL, "Portuguese");

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

int querjogar = 1;
while (querjogar == 1) {

	int segundos = time(0);
	srand(segundos);
	int numerasso = rand();

	int NTENTATIVAS;
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
				if (dificuldade == 1){
					NTENTATIVAS = 15;
				}
				else if (dificuldade == 2){
					NTENTATIVAS = 10;
				}
				else {
					NTENTATIVAS = 5;
				}

	for(int i = 1; i<=NTENTATIVAS ; i++) {

		printf("\n");
		printf("tentativa %d de %d\n", tentativas, NTENTATIVAS);
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
printf("deseja jogar novamente?\n");
printf("1 - sim\n");
printf("0 - nao\n");
	int certeza;
	scanf("%d", &certeza);
		if (certeza == 1) {
			continue;
		}
		else if (certeza == 0) {
			break;
		}
}
}	
