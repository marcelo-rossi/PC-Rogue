#include "graficos.h"
#include "auxiliares.h"
#include "heroi.h"
#include "mapa.h"
#include "varGlobal.h"

void desenhaUI(void){
    gotoxy(11,0);
    printf("Sala atual (%d,%d)", gameHero.mapa.x,gameHero.mapa.y);
    gotoxy(11,1);
    printf("Voce esta no andar %d", gameHero.level);
    gotoxy(11,2);
    printf("Pontos de vida %d", gameHero.HP);
    gotoxy(1,11);
    printf("Objetivo: Encontrar a escada %%");
    gotoxy(1,12);
    printf("Cuidado com os inimigos: s");
    gotoxy(1,13);
    printf("Use %c %c %c %c para mover",17,30,31,16);
    gotoxy(1,14);
    printf("Use A W S D para mover");
    gotoxy(1,15);
    printf("Use ESC para sair do jogo");
}
