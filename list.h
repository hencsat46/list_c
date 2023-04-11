#ifndef SUPPORT_FUNC_H
#define SUPPORT_FUNC_H
#include "typedefs.h"


void show_string(char* string);
List * new_list(char *format, ...);
void free_list(List *list);
void push_list(List *list, char *format, ...);
void pop_elem(List *list);
void show_string(char *string);
char *format_double(double num);
void print_list(List *list);
int list_length(List *list);
void insert_elem(List *list, int index, char format, var elem);

#endif // SUPPORT_FUNC_H