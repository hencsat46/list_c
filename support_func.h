#ifndef SUPPORT_FUNC_H
#define SUPPORT_FUNC_H
#include "typedefs.h"

char *format_double(double num);
void show_args(char* types, ...);
void show_string(char* string);
void new_list(List *list, char *format, ...);

#endif // SUPPORT_FUNC_H