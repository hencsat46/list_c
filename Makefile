all: main lib

main: main.c list.h
	gcc main.c -L./libs -lList -o main 2>/dev/null
	

libList: list.c list.h format_double.c format_double.h
	gcc -shared list.c -fPIC -o ./libs/libList.so