#include <windows.h>
#include <conio.h>
#include "auxiliares.h"

void gotoxy(int x,int y);
void hidecursor(void);

int inicio(void) {
    int opcao = 0;
    system("cls");

    // imprime a barra superior
    printf("%c", 201);
    for (int i = 0; i < (SCREENLENGTH); i++){
        printf("%c", 205);
    }
    printf("%c\n", 187);
    
    // imprime as barras laterais
    for(int i = 0; i<(SCREENWIDTHS); i++){
        printf("%c",186);
        printf("Ajuste a janela ate arrumar o contorno da tela");
        for (int j = 46; j < (SCREENLENGTH); j++){
            printf("%c", WHITESPACE);
        }
        printf("%c\n",186);
    }

    // imprime a barra inferior
    printf("%c", 200);
    for (int i = 0; i < (SCREENLENGTH); i++){
        printf("%c", 205);
    }
    printf("%c", 188);

    hidecursor();
}
