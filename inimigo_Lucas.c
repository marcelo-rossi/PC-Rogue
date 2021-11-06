#include "inimigo.h"
#include "auxiliares.h"
#include "iniciajogo.h"
#include "getinput.h"
#include "mapa.h"
#include "heroi.h"
#include "varGlobal.h"
#include "graficos.h"

void criaInimigos(void) {
    //struct Slime *inimigoLista;
    //if (inimigoLista != NULL)
    //inimigoLista = criaInimigosLista();
    for (int i = 0; i<gameHero.level; i++) {
        insereInimigoLista(inimigoLista);
    }
}

struct Slime *criaInimigosLista(void)
{
    struct Slime *start;
    
    start = (struct Slime *) malloc(sizeof(struct Slime));
    start->prox = NULL;
    return start;
}

void insereInimigoLista(struct Slime *p)
{
    struct Slime *novo, *i;

    novo = (struct Slime *) malloc(sizeof(struct Slime));
    for (i = p; i->prox != NULL; i = i->prox);
    i->prox = novo;
    novo->prox = NULL;
    posicionaInimigo(novo);
}

void posicionaInimigo(struct Slime *inimigo){
    int mapaX;
    int mapaY;
    int salaX;
    int salaY;
    char ok = 0;
    do
    {   
        mapaX = rand() % 10;
        if (mapaX > 9){
            mapaX = 9;
        }
        
        mapaY = rand() % 10;
        if (mapaY > 9){
            mapaY = 9;
        }
        
        salaX = rand() % 10;
        if (salaX < 1){
            salaX = 1;
        }
        
        if (salaX > 8){
            salaX = 8;
        }
        
        salaY = rand() % 10;
        if (salaY < 1){
            salaY = 1;
        }
        
        if (salaY > 8){
            salaY = 8;
        }
        ok = ocupado(mapaX,mapaY,salaX,salaY, inimigoLista);
    } while (ok !=0);
    inimigo->mapa.x = mapaX;
    inimigo->mapa.y = mapaY;
    inimigo->sala.x = salaX;
    inimigo->sala.y = salaY;
    inimigo->atual.x = inimigo->sala.x;
    inimigo->atual.y = inimigo->sala.y;
    inimigo->dano = 2;
    inimigo->HP = 10;
    inimigo->display = 's';
    inimigo->vivo = 1;
    if ((inimigo->mapa.x == gameHero.mapa.x) &&
        (inimigo->mapa.y == gameHero.mapa.y)){
            salaAtual.tiles[inimigo->sala.y][inimigo->sala.x] = inimigo->display;
        }
}

int ocupado(int mx, int my, int sx, int sy, struct Slime *lista){

    if ((mx == gameHero.mapa.x) &&
        (my == gameHero.mapa.y) &&
        (sx == gameHero.sala.x) &&
        (sy == gameHero.sala.y)){
        return 1;
    }
    
    struct Slime *i;
    for (i = lista; i->prox != NULL; i = i->prox){
        if ((mx == i->mapa.x) &&
        (my == i->mapa.y) &&
        (sx == i->sala.x) &&
        (sy == i->sala.y)){
        return 1;
        }
    }
    return 0;
}

void inimigoTurno(void) {
    acaoInimigo(inimigoLista);
    mataInimigos(inimigoLista);
}

// Apaga o inimigo da lista
void mataInimigos(struct Slime *inimigo) {
    struct Slime *anterior, *atual;
    anterior = inimigo;
    while(anterior->prox != NULL) {
        atual = anterior->prox;
        if (atual->HP < 1) {
            anterior->prox = atual->prox;
            free(atual);
        } else {
            anterior = anterior->prox;
        }
    }
}

    // struct Slime *anterior, *atual;
    // anterior = inimigo;
    // while(anterior->prox != NULL) {
    //     atual = anterior->prox;
    //     anterior->prox = atual->prox;
    //     free(atual);
    // }


// O que o inimigo faz se esta em sala diferente
void acaoInimigo(struct Slime *inimigo) {
    struct Slime *anterior, *atual;
    anterior = inimigo;
    atual = anterior->prox;
    while(anterior->prox != NULL) {
        
        int heroX = gameHero.mapa.x;
        int inmigoX = atual->mapa.x;
        int heroY = gameHero.mapa.y;
        int inimigoY = atual->mapa.y;
        int difMapaX = heroX - inmigoX;
        int difMapaY = heroY - inimigoY;

        // Move os inimigos em direção à sala que está o heroi
        if ((difMapaX > 0) && (difMapaY < 0))//Heroi na (1,1) inimigo na (0,2)
        {
            atual->sala.x += INIMIGOMOV;
            atual->sala.y -= INIMIGOMOV;
        }
        if ((difMapaX > 0) && (difMapaY == 0))//Heroi na (1,1) inimigo na (0,1)
        {
            atual->sala.x += INIMIGOMOV;
        }
        if ((difMapaX > 0) && (difMapaY > 0))//Heroi na (1,1) inimigo na (0,0)
        {
            atual->sala.x += INIMIGOMOV;
            atual->sala.y += INIMIGOMOV;
        }
        if ((difMapaX == 0) && (difMapaY > 0))//Heroi a (1,1) inimigo na (1,0)
        {
            atual->sala.y += INIMIGOMOV;
        }
        if ((difMapaX < 0) && (difMapaY > 0))//Heroi na (1,1) inimigo na (2,0)
        {
            atual->sala.x -= INIMIGOMOV;
            atual->sala.y += INIMIGOMOV;
        }
        if ((difMapaX < 0) && (difMapaY == 0))//Heroi na (1,1) inimigo na (2,1)
        {
            atual->sala.x -= INIMIGOMOV;
        }
        if ((difMapaX < 0) && (difMapaY < 0))//Heroi na (1,1) inimigo an (2,2)
        {
            atual->sala.x -= INIMIGOMOV;
            atual->sala.y -= INIMIGOMOV;
        }
        if ((difMapaX == 0) && (difMapaY < 0))//Heroi na (1,1) inimigo na (1,2)
        {
            atual->sala.y -= INIMIGOMOV;
        }

        atual->atual.x = atual->sala.x;
        atual->atual.y = atual->sala.y;

        if ((difMapaX == 0) && (difMapaY == 0))//Heroi na mesma sala (0,0)
        {
            acaoInimigo2(atual);
        }

        // Muda o inimigo de sala
        if (atual->sala.x > 9){
            atual->sala.x = 0;
            atual->atual.x = atual->sala.x;
            atual->mapa.x++;
        }
        if (atual->sala.x < 0){
            atual->sala.x = 9;
            atual->atual.x = atual->sala.x;
            atual->mapa.x--;
        }
        if (atual->sala.y > 9){
            atual->sala.y = 0;
            atual->atual.y = atual->sala.y;
            atual->mapa.y++;
        }
        if (atual->sala.y < 0){
            atual->sala.y = 9;
            atual->atual.y = atual->sala.y;
            atual->mapa.y--;
        }
        anterior = anterior->prox;
        atual = anterior->prox;
    }
}

// O que o inimigo faz se esta na mesma sala
void acaoInimigo2(struct Slime *inimigo) {

    int difSalaX = gameHero.sala.x - inimigo->sala.x;
    int difSalaY = gameHero.sala.y - inimigo->sala.y;
    if ((difSalaX > 0) && (difSalaY < 0))//Heroi na (1,1) inimigo na (0,2)
    {
        if (difSalaX > difSalaY) {
            inimigo->sala.x += INIMIGOMOV;
        } else {
            inimigo->sala.y -= INIMIGOMOV;
        }
    }
    if ((difSalaX > 0) && (difSalaY == 0))//Heroi na (1,1) inimigo na (0,1)
    {
        inimigo->sala.x += INIMIGOMOV;
    }
    if ((difSalaX > 0) && (difSalaY > 0))//Heroi na (1,1) inimigo na (0,0)
    {
        if (difSalaX > difSalaY*-1) {
            inimigo->sala.x += INIMIGOMOV;
        } else {
            inimigo->sala.y += INIMIGOMOV;
        }
    }
    if ((difSalaX == 0) && (difSalaY > 0))//Heroi a (1,1) inimigo na (1,0)
    {
        inimigo->sala.y += INIMIGOMOV;
    }
    if ((difSalaX < 0) && (difSalaY > 0))//Heroi na (1,1) inimigo na (2,0)
    {
        if (difSalaX*-1 > difSalaY*-1) {
            inimigo->sala.x -= INIMIGOMOV;
        } else {
            inimigo->sala.y += INIMIGOMOV;
        }
    }
    if ((difSalaX < 0) && (difSalaY == 0))//Heroi na (1,1) inimigo na (2,1)
    {
        inimigo->sala.x -= INIMIGOMOV;
    }
    if ((difSalaX < 0) && (difSalaY < 0))//Heroi na (1,1) inimigo an (2,2)
    {
        if (difSalaX*-1 > difSalaY) {
            inimigo->sala.x -= INIMIGOMOV;
        } else {
            inimigo->sala.y -= INIMIGOMOV;
        }
    }
    if ((difSalaX == 0) && (difSalaY < 0))//Heroi na (1,1) inimigo na (1,2)
    {
        inimigo->sala.y -= INIMIGOMOV;
    }
    
    // Se o inimigo chegar na posição do heroi ataca ele, se não atualiza a posição
    if ((inimigo->sala.x == gameHero.sala.x) &&
        (inimigo->sala.y == gameHero.sala.y)) {
            gameHero.HP -= inimigo->dano;
            inimigo->sala.x = inimigo->atual.x;
            inimigo->sala.y = inimigo->atual.y;

    } else {
        inimigo->atual.x = inimigo->sala.x;
        inimigo->atual.y = inimigo->sala.y;
    }
    salaAtual.tiles[inimigo->sala.y][inimigo->sala.x] = inimigo->display;
}