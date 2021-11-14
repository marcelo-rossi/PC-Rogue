#include "auxiliares.h"
#include "iniciajogo.h"
#include "getinput.h"
#include "mapa.h"
#include "heroi.h"
#include "varGlobal.h"
#include "graficos.h"
#include "inimigo.h"

void iniciaJogo(void)
{
    if (newGame == 1) {
        gameHero.level = 0;
        gameHero.dano = 10;
        gameHero.HP = 100;
        gameHero.vivo = 1;
    }
    mataTodos(inimigoLista);
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
        inimigoTurno();
        // Verifica se o heroi morreu para o game over
        if (gameHero.HP < 1) {
            gameHero.vivo = 0;
            input = 0;
        }
    } while (input != ESC);
}


