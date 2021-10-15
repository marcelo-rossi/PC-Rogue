#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "inicio.c"
#include "mainmenu.c"
#include "auxiliares.c"
#include "auxiliares.h"
#include "iniciajogo.c"
#include "carregajogo.c"


int main (void)
{

   // imprime todos os caratceres
   //for (int i = 0; i<256; i++) {
   //    printf("%d - %c\n", i, i);
   //}
   //getch();

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