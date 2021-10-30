#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "inicio.h"
#include "mainmenu.h"
#include "auxiliares.h"
#include "iniciajogo.h"
#include "carregajogo.h"
#include "mapa.h"
#include "heroi.h"

struct salas matrizMapa [10][10];
struct salas salaAtual;
struct Heroi gameHero;

int main (void)
{

   hidecursor();
   inicio();
   getch();
   int menuOption = menuDisplay();
   switch (menuOption)
   {
      case 0: //para cima
         iniciaJogo();
         break;
      case 1: //para baixo
         carregaJogo();
         break;
   }
   return 0;
}