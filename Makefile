

main : typedefs.h main.c support_func.c support_func.h
	gcc main.c typedefs.h support_func.c support_func.h -o main
