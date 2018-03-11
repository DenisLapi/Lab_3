all: program

program: main.o io.o mat.o
	gcc main.c io.c mat.c -o application

main.o: main.c
	gcc -c main.c

io.o: io.c
	gcc -c io.c

mat.o: mat.c
	gcc -c mat.c
