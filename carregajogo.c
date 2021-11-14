#include "carregajogo.h"
#include <conio.h>
#include "mainmenu.h"
#include "auxiliares.h"
#include "iniciajogo.h"
#include "inicio.h"
#include "mapa.h"
#include "heroi.h"
#include "inimigo.h"
#include "gameover.h"
#include "varGlobal.h"

void carregaJogo(void)
{
    FILE *fp;
    int filesize;
    
    fp = fopen("savegame.sav", "rb"); // Abre o arquivo no modo leitura
    
    if (fp == NULL) { // Testa se o arquivo existe se não existe apresenta mensagem
        mensagemNoFile();
        fclose(fp);
    } else { // Se o arquivo existe testa o tamanho dele
        fseek (fp, 0, SEEK_END);
        filesize = ftell(fp);
        if (filesize == 0) { // se o arquivo estiver vazio apresenta mensagem
            mensagemFileEmpty();
            fclose(fp);
        } else { // O arquivo existe e não está vazio
            fclose(fp);
            carregaJogoDoArquivo();
        }
    }
}

void mensagemNoFile(void) {
    gotoxy(SCREENHEIGHT/2-10,SCREENWIDTHS/2-2);
    printf("%c", 201);
    for (int i = 0; i < 25; i++){
        printf("%c", 205);
    }
    printf("%c", 187);
    gotoxy(SCREENHEIGHT/2-10,SCREENWIDTHS/2-1);
    printf("%c", 186);
    for (int i = 0; i < 25; i++){
        printf("%c", 32);
    }
    printf("%c", 186);
    gotoxy(SCREENHEIGHT/2-10,SCREENWIDTHS/2);
    printf("%c",186);
    printf("%c",32);
    printf("Arquivo nao encontrado!");
    printf("%c",32);
    printf("%c",186);
    gotoxy(SCREENHEIGHT/2-10,SCREENWIDTHS/2+1);
    printf("%c", 186);
    for (int i = 0; i < 25; i++){
        printf("%c", 32);
    }
    printf("%c", 186);
    gotoxy(SCREENHEIGHT/2-10,SCREENWIDTHS/2+2);
    printf("%c", 200);
    for (int i = 0; i < 25; i++){
        printf("%c", 205);
    }
    printf("%c", 188);
    getch();
}

void mensagemFileEmpty(void) {
    gotoxy(SCREENHEIGHT/2-10,SCREENWIDTHS/2-2);
    printf("%c", 201);
    for (int i = 0; i < 25; i++){
        printf("%c", 205);
    }
    printf("%c", 187);
    gotoxy(SCREENHEIGHT/2-10,SCREENWIDTHS/2-1);
    printf("%c", 186);
    for (int i = 0; i < 25; i++){
        printf("%c", 32);
    }
    printf("%c", 186);
    gotoxy(SCREENHEIGHT/2-10,SCREENWIDTHS/2);
    printf("%c",186);
    printf("%c",32);
    printf("O arquivo esta vazio!!!");
    printf("%c",32);
    printf("%c",186);
    gotoxy(SCREENHEIGHT/2-10,SCREENWIDTHS/2+1);
    printf("%c", 186);
    for (int i = 0; i < 25; i++){
        printf("%c", 32);
    }
    printf("%c", 186);
    gotoxy(SCREENHEIGHT/2-10,SCREENWIDTHS/2+2);
    printf("%c", 200);
    for (int i = 0; i < 25; i++){
        printf("%c", 205);
    }
    printf("%c", 188);
    getch();
}

void carregaJogoDoArquivo(void) {
    FILE * fp= fopen("savegame.sav", "rb");
    
    if (fp != NULL) {
        fread(&gameHero, sizeof(struct Heroi), 1, fp);
    }
    fclose(fp);
    newGame = 0;
    iniciaJogo();
        if (gameHero.vivo == 0){
            gameOver();
        }
}

void salvaJogoNoArquivo(void) {
    FILE * fp= fopen("savegame.sav", "wb");
    
    if (fp != NULL) {
        fwrite(&gameHero, sizeof(struct Heroi), 1, fp);
    }
    fclose(fp);
}