all: main libList

main: main.c list.h
	gcc main.c -L./libs -lList -o main
	

libList: list.c list.h
	gcc -shared list.c -fPIC -o ./libs/libList.so