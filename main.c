#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    printf("seja bem vindo aos 3 jogos que desenvolvi durante meu aprendizado nos cursos da ALURA\n");
    printf("- todos os jogos foram aprimorados por mim após o termino do curso com conhecimentos que adiquiri durante os cursos e a faculdade\n");
    printf("- este menu é somente uma forma de juntar todos os 3 em um unico arquivo executavel\n");
    printf("- tentei otimizar ao maximo ultilizando uma ampla variedade de conhecimentos que adiquiri durante o curso\n");
    printf("- informações mais especificas no meu perfil no github/luckasklopes\n\n");
    printf("pressione qualquer tecla para continuar..");
        getchar();
        system("cls");
        printf("\n");
    int dnv = 1;
    do {
        printf("Qual jogo você deseja jogar?\n");
        printf("1 - chute: seu objetivo é tentar acertar o numero aleatorio com o menor numero de chutes possivel\n");
        printf("2 - forca: seu objetivo é acertar a palavra secreta com o minimo de erros possivel\n");
        printf("3 - corre: WIP\n");
        printf("0 - sair\n");
        int opc; scanf("%d", &opc);
            system("cls");
        switch(opc) {
            case 1:
                printf("aqui sera o jogo de acertar numeros aleatorios\n\n");
                break;
            case 2:
                printf("aqui sera o jogo da forca\n\n");
                break;
            case 3:
                printf("work in progress\n\n");
                break;
            case 0:
                exit(0);
            default:
                continue;
        }
    } while(dnv == 1);
}