prog: main.o functions.o
	gcc -o prog main.o functions.o 

main.o: main.c functions.h structs.h
	gcc -c main.c functions.h structs.h

functions.o: functions.c functions.h structs.h
	gcc -c functions.c functions.h structs.h