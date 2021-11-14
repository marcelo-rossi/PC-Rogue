#include <stdlib.h>
#include "auxiliares.h"
#include "getinput.h"
#include "mapa.h"
#include "heroi.h"
#include "varGlobal.h"
#include "carregajogo.h"


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
            heroiAtaca();
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

void heroiAtaca(void) {
    struct Slime *anterior, *atual;
    anterior = inimigoLista;
    atual = anterior->prox;
    while(anterior->prox != NULL) {
        // verifica se o inimigo está na mesma sala que o heroi
        if ((atual->mapa.x == gameHero.mapa.x) &&
            (atual->mapa.y == gameHero.mapa.y)) {
                // verifica se o inimog está na mesma posição do heroi
                if ((atual->sala.x == gameHero.sala.x) &&
                    (atual->sala.y == gameHero.sala.y)) {
                        atual->HP -= gameHero.dano;
                }
        }
        anterior = anterior->prox;
        atual = anterior->prox;
    }

    // for (int i = 0; i < 10; i++){
    //     // verifica se o inimigo está na mesma sala que o heroi
    //     if ((inimigos[i].mapa.x == gameHero.mapa.x) &&
    //         (inimigos[i].mapa.y == gameHero.mapa.y)) {
    //             // verifica se o inimog está na mesma posição do heroi
    //             if ((inimigos[i].sala.x == gameHero.sala.x) &&
    //                 (inimigos[i].sala.y == gameHero.sala.y)) {
    //                     inimigos[i].HP -= gameHero.dano;
    //             }
    //     }
    // }
    gameHero.sala.x = gameHero.atual.x;
    gameHero.sala.y = gameHero.atual.y;
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
    gameHero.level++;
    salvaJogoNoArquivo();
    mataTodos(inimigoLista);
    criaMapa();    
}

// Apaga a lista de inimigos para criar uma nova no próximo level.
void mataTodos(struct Slime *inimigo) {
    struct Slime *anterior, *atual;
    anterior = inimigo;
    while(anterior->prox != NULL) {
        atual = anterior->prox;
        anterior->prox = atual->prox;
        free(atual);
    }
}
