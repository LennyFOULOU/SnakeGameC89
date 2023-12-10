jeu : main.o fond.o serpent.o fruit.o
	gcc -ansi -pedantic -o jeu main.o fond.o fruit.o serpent.o -lgraph

fond.o : fond.c
	gcc -ansi -pedantic -c fond.c

fruit.o : fruit.c fruit.h
	gcc -ansi -pedantic -c fruit.c

serpent.o : serpent.c
	gcc -ansi -pedantic -c serpent.c

main.o  : main.c fond.h fruit.h serpent.h 
	gcc -ansi -pedantic -c main.c

clean :
	rm -f jeu *.o

.PHONY :  clean
