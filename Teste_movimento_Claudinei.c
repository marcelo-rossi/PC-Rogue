#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getinput.h>


void movimento(void)
{
    int i,j;
    int matrizSala [10][10];
    int matrizMapa [10][10];
    int tecla;
    char input = 0;
    int opcao=0;
    
    matrizMapa[i][j]==matrizSala[i][j];
    srand(time(NULL));
    
    //sorteio Coordenadas matrizMapa
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            matrizMapa[i][j] = rand() % 10;
        }
    }

    //sorteio Coordenadas matrizSala
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            matrizSala[i][j] = 1 + (rand() % 9);
        }
    }
    printf("O personagem nasceu na coordenada do mapa: [%d][%d]\n",rand() % 10,rand() % 10);
    printf("O personagem nasceu na coordenada da sala: [%d][%d]\n",1 + (rand() % 9),1 + (rand() % 8));
    tecla=getch();
    printf("\n");

    //declaracao da matrizSala
    //Se houver algum comando para simplificar essa parte, sera bem vindo.
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            matrizSala[i][j]=1;
            if(matrizSala[i][j]==1){
                matrizSala[0][0]=0;
                matrizSala[0][1]=0;
                matrizSala[0][2]=0;
                matrizSala[0][3]=0;
                matrizSala[0][4]=2;
                matrizSala[0][5]=2;
                matrizSala[0][6]=0;
                matrizSala[0][7]=0;
                matrizSala[0][8]=0;
                matrizSala[0][9]=0;
                matrizSala[9][0]=0;
                matrizSala[9][1]=0;
                matrizSala[9][2]=0;
                matrizSala[9][3]=0;
                matrizSala[9][4]=2;
                matrizSala[9][5]=2;
                matrizSala[9][6]=0;
                matrizSala[9][7]=0;
                matrizSala[9][8]=0;
                matrizSala[9][9]=0;
                matrizSala[1][0]=0;
                matrizSala[2][0]=0;
                matrizSala[3][0]=0;
                matrizSala[4][0]=2;
                matrizSala[5][0]=2;
                matrizSala[6][0]=0;
                matrizSala[7][0]=0;
                matrizSala[8][0]=0;
                matrizSala[1][9]=0;
                matrizSala[2][9]=0;
                matrizSala[3][9]=0;
                matrizSala[4][9]=2;
                matrizSala[5][9]=2;
                matrizSala[6][9]=0;
                matrizSala[7][9]=0;
                matrizSala[8][9]=0;
            }
        }
    }
    //tentativa falha de colocar o getInput
    
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