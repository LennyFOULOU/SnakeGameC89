jeu: main.o serpent.o fruit.o fond.o boss.o menu.o
	gcc -ansi -pedantic -o jeu main.o fruit.o serpent.o fond.o boss.o menu.o -lgraph

main.o: main.c 
	gcc -ansi -pedantic -c main.c

serpent.o: serpent.c
	gcc -ansi -pedantic -c serpent.c

fruit.o: fruit.c
	gcc -ansi -pedantic -c fruit.c

fond.o: fond.c 
	gcc -ansi -pedantic -c fond.c

boss.o: boss.c
	gcc -ansi -pedantic -c boss.c

menu.o: menu.c
	gcc -ansi -pedantic -c menu.c 

clean:
	rm -f jeu *.o
	
run:
	./jeu

.PHONY: run clean
