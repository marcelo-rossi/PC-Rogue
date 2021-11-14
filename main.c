#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "mainmenu.h"
#include "auxiliares.h"
#include "iniciajogo.h"
#include "inicio.h"
#include "carregajogo.h"
#include "mapa.h"
#include "heroi.h"
#include "gameover.h"
#include "inimigo.h"

struct salas matrizMapa [10][10];
struct salas salaAtual;
struct Heroi gameHero;
struct Slime inimigos [10];
struct Slime *inimigoLista;
char newGame = 1;

int main (void)
{

   inimigoLista = NULL;
   inimigoLista = criaInimigosLista();
   hidecursor();
   inicio();
   getch();
   int menuOption = 4;
   do {
      menuOption = menuDisplay();
      switch (menuOption)
      {
         case 0: //para cima
            newGame = 1;
            iniciaJogo();
            if (gameHero.vivo == 0){
               gameOver();
            }
            break;
         case 1: //para baixo
            carregaJogo();
            break;
      }
   } while (menuOption != 2);
   return 0;
}