all: project3-main.o cards.o
	gcc project3-main.o cards.o -o CardGame
project3-main.o: project3-main.c cards.h
	gcc -c project3-main.c -o project3-main.o
cards.o: cards.c cards.h
	gcc -c cards.c -o cards.o
clean:
	rm -rf *.o
	rm CardGame

