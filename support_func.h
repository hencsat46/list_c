#ifndef SUPPORT_FUNC_H
#define SUPPORT_FUNC_H
#include "typedefs.h"

char *format_double(double num);
void show_args(char* types, ...);
void show_string(char* string);
List * new_list(char *format, ...);
void free_list(List *list);
void push_list(List *list, char *format, ...);
void print_list(List *list);
#endif // SUPPORT_FUNC_H