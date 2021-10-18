all: main.o auxiliares.o carregajogo.o getinput.o iniciajogo.o inicio.o mainmenu.o
	gcc -Wall main.o auxiliares.o carregajogo.o getinput.o iniciajogo.o inicio.o mainmenu.o -o PC-Rogue.exe

main.o: main.c
	gcc -Wall -c main.c

auxiliares.o: auxiliares.c
	gcc -Wall -c auxiliares.c

carregajogo.o: carregajogo.c
	gcc -Wall -c carregajogo.c

getinput.o: getinput.c
	gcc -Wall -c getinput.c

iniciajogo.o: iniciajogo.c
	gcc -Wall -c iniciajogo.c

inicio.o: inicio.c
	gcc -Wall -c inicio.c

mainmenu.o: mainmenu.c
	gcc -Wall -c mainmenu.c

clear:
	rm -f PC-Rogue.exe main.o auxiliares.o carregajogo.o getinput.o iniciajogo.o inicio.o mainmenu.o