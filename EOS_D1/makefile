all: MyProgram
MyProgram: main.o input.o
	gcc -o MyProgram main.o input.o
main.o: main.c input.h
	gcc -c main.c
input.o: input.c input.h
	gcc -c input.c
.PHONY: clean
clean:
	rm -f MyProgram *.o
