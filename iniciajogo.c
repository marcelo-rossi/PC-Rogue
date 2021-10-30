#include "auxiliares.h"
#include "iniciajogo.h"
#include "getinput.h"
#include "mapa.h"
#include "heroi.h"
#include "varGlobal.h"

void iniciaJogo(void)
{
    /* Anterior
    system("cls");
    printf("Fazer a rotina para iniciar o jogo!!!");
    getchar();
    */
    criaMapa();
    char input = 0;
    do
    {
        // Desenha o mapa onde o heroi está
        desenhaMapa(salaAtual);
        desenhaUI();
        // Lê entrada do teclado
        input = getInput();
        switch (input)
        {
            case UP: //para cima
                gameHero.sala.y--;
                break;
            case DONW: //para baixo
                gameHero.sala.y++;
                break;
            case RIGHT: //para direita
                gameHero.sala.x++;
                break;
            case LEFT: //para esquerda
                gameHero.sala.x--;
                break;
            default :
                break;
        }
        acaoHeroi();

    } while (input!=0);
}
void acaoHeroi(void)
{
    char opcaoAcao = salaAtual.tiles[gameHero.sala.y][gameHero.sala.x];
    switch (opcaoAcao)
    {
        case PAREDE: //Heroi bateu na parede não pode mover
            parede();
            break;
        case CHAO: //Heroi pode mover
            moveHeroi();
            break;
        case PORTA: //Heroi encontrou uma porta
            //moveHeroi();
            entraPorta();
            break;
        case ESCADA: //Heroi encontrou a escada
            moveHeroi();
            sobeEscada();
            break;
        default :
            break;
    }
}
void parede(void){
    gameHero.sala.x = gameHero.atual.x;
    gameHero.sala.y = gameHero.atual.y;
    salaAtual = matrizMapa[gameHero.mapa.y][gameHero.mapa.x];
    salaAtual.tiles[gameHero.sala.y][gameHero.sala.x] = 4;
}
void moveHeroi(void){
    gameHero.atual.x = gameHero.sala.x;
    gameHero.atual.y = gameHero.sala.y;
    salaAtual = matrizMapa[gameHero.mapa.y][gameHero.mapa.x];
    salaAtual.tiles[gameHero.sala.y][gameHero.sala.x] = 4;
}
void entraPorta(void){
    if (gameHero.atual.x == 1){
        gameHero.atual.x = 8;
        gameHero.sala.x = gameHero.atual.x;
        gameHero.mapa.x--;
        salaAtual = matrizMapa[gameHero.mapa.y][gameHero.mapa.x];
        salaAtual.tiles[gameHero.sala.y][gameHero.sala.x] = 4;
        return;
    }
    if (gameHero.atual.x == 8){
        gameHero.atual.x = 1;
        gameHero.sala.x = gameHero.atual.x;
        gameHero.mapa.x++;
        salaAtual = matrizMapa[gameHero.mapa.y][gameHero.mapa.x];
        salaAtual.tiles[gameHero.sala.y][gameHero.sala.x] = 4;
        return;
    }
    if (gameHero.atual.y == 1){
        gameHero.atual.y = 8;
        gameHero.sala.y = gameHero.atual.y;
        gameHero.mapa.y--;
        salaAtual = matrizMapa[gameHero.mapa.y][gameHero.mapa.x];
        salaAtual.tiles[gameHero.sala.y][gameHero.sala.x] = 4;
        return;
    }
    if (gameHero.atual.y == 8){
        gameHero.atual.y = 1;
        gameHero.sala.y = gameHero.atual.y;
        gameHero.mapa.y++;
        salaAtual = matrizMapa[gameHero.mapa.y][gameHero.mapa.x];
        salaAtual.tiles[gameHero.sala.y][gameHero.sala.x] = 4;
        return;
    }
}

void sobeEscada(void){
    
}

void desenhaUI(void){
    gotoxy(11,0);
    printf("Sala atual (%d,%d)", gameHero.mapa.x,gameHero.mapa.y);
    gotoxy(1,11);
    printf("Objetivo: Encontrar a escada %%");
}
