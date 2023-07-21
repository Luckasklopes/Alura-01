//teste de jogo de adivinhação
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


int main() {
	setlocale(LC_ALL, "Portuguese");

	//printf imprime um texto, \n quebra linha
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

	//short - igual ao int, porém ocupando menos espaço e menores variaveis, de 2 bytes
	//int - forma de guardar variaveis inteiras ocupando 4 bytes
	//long - igual ao int, porem podendo armazenar variaveis maiores, de 8 bytes

	//float - semelhante a double, porém ocupando menos espaço e menores variaveis, somente 4 bytes
	//double - forma de guardar variaveis não inteiras ocupando 8 bytes

	int querjogar = 1;
	while (querjogar == 1) {

		int segundos = time(0);
		srand(segundos);
		int numerasso = rand();

		int NTENTATIVAS;
		int nsecreto = numerasso % 100; //% serve para pegar somente o resto da divisão, que nesse caso sempre será algo entre 0 e 99 
		int chute; //int é uma variavel inteira
		int tentativas = 1;
		int ganhou = 0;
		double pontos = 1000;

		//selecionador de dificuldade
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


		for(int i = 1; i<=NTENTATIVAS ; i++) { //while é ultilizado para loops condicionais

			printf("\n"); //printf("O número %d é o secreto, não espalha\n", nsecreto); %d cria uma mascara, colocar variavel dps do texto com virgula
			printf("tentativa %d de %d\n", tentativas, NTENTATIVAS);
			printf("Qual o seu chute?");

			scanf("%d", &chute); //corno não explicou oq é & //scan pede pro usuario digitar
			printf("seu chute foi %d\n", chute);
			//printf("teste de print %d %d\n", nsecreto, chute); //quantas  %d eu colocar, terei q por variais para linkar depois

			if (chute < 0) {
				printf("voce nao pode chutar numeros negativos, seu animal\n");
				
				continue; // interrompe o loop do "for" caso verdadeiro
			}
			else if (chute == nsecreto) { // == é ultilizado para comparar variaveis
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

				tentativas = tentativas + 1; //possui o mesmo efeito de escrever "tentativas++"
			}
					double subpontos = (chute - nsecreto) * (double)2; //double é ultilizado para variaveis não inteiras, (double) é para quando naquele momento especifico, aquela variavel ou numero precisa ser tratada como double
			pontos = abs(pontos) - abs(subpontos);

	}

	printf("\n");
	printf("\n");
		if (ganhou == 1){
			printf("Parabens!! voce ganhou\n");
			tentativas--;
			printf("voce acertou em %d tentativas e fez %.1f pontos\n", tentativas, pontos);//%f é a mascara ultilizada quando o tipo de variavel é double, %.1f é para que sejam ultilizadas somente uma casa decimal pós virgula
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