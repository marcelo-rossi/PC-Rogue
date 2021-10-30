#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "auxiliares.h"
#include "getinput.h"
#include "mapa.h"
#include "heroi.h"
#include "varGlobal.h"

struct salas criaSala(char desenho[10][10]){
    struct salas desenhoSala;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            desenhoSala.tiles[i][j] = desenho[i][j];
    return desenhoSala;
}

void criaMapa(void)
{
    int i,j;
    struct salas matrizSala;
    int saidaX;
    int saidaY;
//    int tecla;
    
    srand(time(NULL));
    // Define em qual sala está a saída
    saidaX = rand() % 10;
    saidaY = rand() % 10;
    
//    printf("O personagem nasceu na coordenada do mapa: [%d][%d]\n",rand() % 10,rand() % 10);
//    printf("O personagem nasceu na coordenada da sala: [%d][%d]\n",1 + (rand() % 9),1 + (rand() % 8));
//    //tecla=getch();
//    printf("\n");

    //declaracao da matrizSala
    //Se houver algum comando para simplificar essa parte, sera bem vindo.
    {// Cria a sala na coordenada (0,0)
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10]= {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 2},///4
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 2},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 2, 2, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    matrizMapa[0][0] = matrizSala;}
    {// Cria a sala na coordenada (0,9)
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10]= {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 0},///4
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 0},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 2, 2, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    matrizMapa[0][9] = matrizSala;}
    {// Cria a sala na coordenada (9,9)
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10]= {{0, 0, 0, 0, 2, 2, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 0},///4
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 0},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    matrizMapa[9][9] = matrizSala;}
    {// Cria a sala na coordenada (9,0)
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10]= {{0, 0, 0, 0, 2, 2, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 2},///4
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 2},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    matrizMapa[9][0] = matrizSala;}
    {// Cria as salas na latereal esquerda
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10]= {{0, 0, 0, 0, 2, 2, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 2},///4
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 2},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 2, 2, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    for (i = 1; i < 9; i++)
        matrizMapa[i][0] = matrizSala;}
    {// Cria as salas na latereal direita
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10] ={{0, 0, 0, 0, 2, 2, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 0},///4
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 0},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 2, 2, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    for (i = 1; i < 9; i++)
        matrizMapa[i][9] = matrizSala;}
    {// Cria as salas no lado superior
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10]= {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},///4
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 2, 2, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    for (i = 1; i < 9; i++)
        matrizMapa[0][i] = matrizSala;}
    {// Cria as salas no lado inferior
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10]= {{0, 0, 0, 0, 2, 2, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},///4
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    for (i = 1; i < 9; i++)
        matrizMapa[9][i] = matrizSala;}
    {// Cria as salas no meio do mapa
    /////////////////////0  1  2  3  4  5  6  7  8  9
    char sala[10][10]= {{0, 0, 0, 0, 2, 2, 0, 0, 0, 0},///0
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///1
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///2
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///3
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},///4
                        {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},///5
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///6
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///7
                        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},///8
                        {0, 0, 0, 0, 2, 2, 0, 0, 0, 0}};//9)
    matrizSala = criaSala(sala);
    for (i = 1; i < 9; i++)
        for (j = 1; j < 9; j++)
           matrizMapa[i][j] = matrizSala;}
    
    // Coloca a saida no mapa
    matrizMapa[saidaY][saidaX].tiles[4][5] = 3;
    // Coloca o heroi em algum lugar do mapa
    gameHero.mapa.x = rand() % 10;
    gameHero.mapa.y = rand() % 10;
    gameHero.sala.x = rand() % 10;
    gameHero.sala.y = rand() % 10;
    gameHero.atual.x = gameHero.sala.x;
    gameHero.atual.y = gameHero.sala.y;
    salaAtual = matrizMapa[gameHero.mapa.y][gameHero.mapa.x];
    salaAtual.tiles[gameHero.sala.y][gameHero.sala.x] = 4;
    //matrizMapa[gameHero.mapa.y][gameHero.mapa.x].tiles[gameHero.sala.y][gameHero.sala.x] = 4;
// para depuração e visualização de todas as salas
//    for (i = 0; i<10; i++){
//        for (j = 0; j<10; j++){
//            desenhaMapa(matrizMapa[i][j]);
//            tecla=getInput();
//        }
//    }

}

void desenhaMapa(struct salas local)
{
    system("cls");
    gotoxy(0,0);

    for (int ii = 0; ii < 10; ii++){
        for (int jj = 0; jj < 10; jj++){
            //printf("%d",local.tiles[ii][jj]);
            switch (local.tiles[ii][jj]){
                case 0: //parede
                    printf("%c",219);
                break;
                case 1: //chão
                    printf(".");
                break;
                case 2: //porta
                    printf("%c",176);
                break;
                case 3: //escada
                    printf("%%");
                break;
                case 4: //heroi
                    printf("%c",2);
                break;
                default:
                    printf("%c",local.tiles[ii][jj]);
                break;
            }
        }
        printf("\n");
    }
}

    
/*    //tentativa falha de colocar o getInput
    
    input = getInput();
    switch (input)
        {
            case UP: //para cima
                opcao--;
                break;
            case DONW: //para baixo
                opcao++;
                break;
            case LEFT: //para cima
                opcao--;
                break;
            case RIGHT: //para baixo
                opcao++;
                break;
            default :
                break;
        }
          
    //Print da matrizSala
    for(i=0;i<10;i++){
        for(j=0;j<10;j++)
            printf("[%d] ",matrizSala[i][j]);
            printf("\n");  
    } 
    tecla=getch(); 
}
*/