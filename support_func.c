#include "support_func.h"
#include "typedefs.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

char* format_double(double num) {
    
    char *old_str = (char *)malloc(64);
    
    sprintf(old_str, "%f", num);
    
    bool dot_state = FALSE, find_zero = FALSE;
    char *ptr_null = NULL;
    
    for (char *ptr = old_str; *ptr; ++ptr) {
        if (*ptr == '0') {
            if (!find_zero) {
                ptr_null = ptr;
                find_zero = TRUE;
            }
        } else {
            find_zero = FALSE;
        }    
    }
    
    char *new_str = NULL;
    if (find_zero) {
        
        size_t size = (ptr_null - old_str + 1);
        new_str = (char *)malloc(size);
        
        for (char *ptr = old_str, *new_ptr = new_str; ptr < ptr_null; ++ptr, ++new_ptr) {
            *new_ptr = *ptr;
        }
        *(new_str + size - 1) = '\0';
        
    }

    free(old_str);
    return new_str;    
}

void show_args(char* types, ...) {
    va_list factor;
    va_start(factor, types);
    var variable;
    for (char* ptr = types; *ptr; ++ptr) {
        switch (*ptr) {
            case 'd':
                variable.digit = va_arg(factor, int);
                printf("%d\n", variable.digit);
                break;
            case 's':
                variable.string = va_arg(factor, char*);
                show_string(variable.string);
                break;
            case 'r':
                variable.real = va_arg(factor, double);
                char *ptr = format_double(variable.real);
                printf("%s", ptr);
                free(ptr);
                break;
        }
        
    }
    printf("\n");
}

void show_string(char* string) {
    for (char *ptr = string; *ptr; ++ptr) {
        printf("%c", *ptr);
    }
    printf("\n");
}