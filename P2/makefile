all: project2-main.o routerecords.o
	gcc project2-main.o routerecords.o -o DatabaseProgram
project2-main.o: project2-main.c routerecords.h
	gcc -c project2-main.c -o project2-main.o
routerecords.o: routerecords.c routerecords.h
	gcc -c routerecords.c -o routerecords.o
clean:
	rm -rf *.o
	rm DatabaseProgram
