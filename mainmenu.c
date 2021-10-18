#include "auxiliares.h"
#include "getinput.h"
#include "mainmenu.h"

void gotoxy(int x,int y);
void opicoes(int op);
void hidecursor(void);
char getInput(void);

int menuDisplay(void) {
    int opcao = 0;
    char input = 0;
    do
    {
        system("cls");

        // imprime a barra superior
        printf("%c", 201);
        for (int i = 0; i < (SCREENLENGTH-1); i++){
            printf("%c", 205);
        }
        printf("%c\n", 187);
    
        // imprime as barras laterais
        for(int i = 0; i<(SCREENWIDTHS-1); i++){
            printf("%c",186);
            for (int j = 0; j < (SCREENLENGTH-1); j++){
                printf("%c", WHITESPACE);
            }
        printf("%c\n",186);
        }

        // imprime a barra inferior
        printf("%c", 200);
        for (int i = 0; i < (SCREENLENGTH-1); i++){
            printf("%c", 205);
        }
        printf("%c", 188);

        opicoes(opcao);
        
        // Lê entrada do teclado
        input = getInput();

        switch (input)
        {
            case 'w': //para cima
                opcao--;
                break;
            case 's': //para baixo
                opcao++;
                break;
            default :
                break;
        }
        // faz o loop no menu
        if (opcao < 0)
            opcao = 2;
        if (opcao > 2)
            opcao = 0;
    } while  (input != 13);
    return opcao;
}

void opicoes(int op)
{
    const int menu1[] = {(SCREENLENGTH >>1) - 4 , (SCREENWIDTHS >> 1) - 2 , 9};
    const int menu2[] = {(SCREENLENGTH >>1) - 9 , (SCREENWIDTHS >> 1) , 19};
    const int menu3[] = {(SCREENLENGTH >>1) - 2 , (SCREENWIDTHS >> 1) + 2 , 4};
    gotoxy(menu1[0],menu1[1]);
    printf("Novo Jogo");
    gotoxy(menu2[0],menu2[1]);
    printf("Carregar Jogo Salvo");
    gotoxy(menu3[0],menu3[1]);
    printf("Sair");

    switch (op)
    {
        case 0:
        gotoxy(menu1[0]-1,menu1[1]-1);
        printf("%c", 201);
        for (int i = 0; i < menu1[2]; i++){
            printf("%c", 205);
        }
        printf("%c\n", 187);
        gotoxy(menu1[0]-1,menu1[1]);
        printf("%cNovo Jogo%c", 186,186);
        gotoxy(menu1[0]-1,menu1[1]+1);
        printf("%c", 200);
        for (int i = 0; i < menu1[2]; i++){
            printf("%c", 205);
        }
        printf("%c\n", 188);
        break;

        case 1:
        gotoxy(menu2[0]-1,menu2[1]-1);
        printf("%c", 201);
        for (int i = 0; i < menu2[2]; i++){
            printf("%c", 205);
        }
        printf("%c\n", 187);
        gotoxy(menu2[0]-1,menu2[1]);
        printf("%cCarregar Jogo Salvo%c", 186,186);
        gotoxy(menu2[0]-1,menu2[1]+1);
        printf("%c", 200);
        for (int i = 0; i < menu2[2]; i++){
            printf("%c", 205);
        }
        printf("%c\n", 188);
        break;

        case 2:
        gotoxy(menu3[0]-1,menu3[1]-1);
        printf("%c", 201);
        for (int i = 0; i < menu3[2]; i++){
            printf("%c", 205);
        }
        printf("%c\n", 187);
        gotoxy(menu3[0]-1,menu3[1]);
        printf("%cSair%c", 186,186);
        gotoxy(menu3[0]-1,menu3[1]+1);
        printf("%c", 200);
        for (int i = 0; i < menu3[2]; i++){
            printf("%c", 205);
        }
        printf("%c\n", 188);
        break;

        default :
        break;
    }
    
    hidecursor();
}

