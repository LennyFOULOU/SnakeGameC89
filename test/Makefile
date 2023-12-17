jeu: main.o serpent.o fruit.o fond.o gameover.o
	gcc -ansi -pedantic -o jeu main.o fruit.o serpent.o fond.o gameover.o -lgraph

main.o: main.c 
	gcc -ansi -pedantic -c main.c

serpent.o: serpent.c
	gcc -ansi -pedantic -c serpent.c

fruit.o: fruit.c
	gcc -ansi -pedantic -c fruit.c

fond.o: fond.c 
	gcc -ansi -pedantic -c fond.c

gameover.o: gameover.c
	gcc -ansi -pedantic -c gameover.c

clean:
	rm -f jeu.o

.PHONY:	clean
