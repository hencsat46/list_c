#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include "consts.h"
#include <string.h>

typedef union {
    int digit;
    uint8_t* string;
    double real;
} var;

void show_string(uint8_t* string) {
    for (uint8_t *ptr = string; *ptr; ++ptr) {
        printf("%c", *ptr);
    }
    printf("\n");
}



uint8_t* format_double(double num) {
    
    uint8_t *old_str = (uint8_t *)malloc(64);
    
    sprintf(old_str, "%f", num);
    
    bool dot_state = FALSE, find_zero = FALSE;
    uint8_t *ptr_null = NULL;
    
    for (uint8_t *ptr = old_str; *ptr; ++ptr) {
        if (*ptr == '0') {
            if (!find_zero) {
                ptr_null = ptr;
                find_zero = TRUE;
            }
        } else {
            find_zero = FALSE;
        }    
    }
    
    uint8_t *new_str = NULL;
    if (find_zero) {
        
        size_t size = (ptr_null - old_str + 1);
        new_str = (uint8_t *)malloc(size);
        
        for (uint8_t *ptr = old_str, *new_ptr = new_str; ptr < ptr_null; ++ptr, ++new_ptr) {
            *new_ptr = *ptr;
        }
        *(new_str + size - 1) = '\0';
        
    }

    free(old_str);
    return new_str;    
}

void show_args(uint8_t* types, ...) {
    va_list factor;
    va_start(factor, types);
    var variable;
    for (uint8_t* ptr = types; *ptr; ++ptr) {
        switch (*ptr) {
            case 'd':
                variable.digit = va_arg(factor, int);
                printf("%d\n", variable.digit);
                break;
            case 's':
                variable.string = va_arg(factor, uint8_t*);
                show_string(variable.string);
                break;
            case 'r':
                variable.real = va_arg(factor, double);
                printf("%10.4f", variable.real);
                break;
        }
        
    }
    printf("\n");
}



void main() {
    //show_args("dddsr", 1, 2, 3, "dick", 1.2);
    
    uint8_t *ptr = format_double(133.14);
    printf("%s\n", ptr);
    free(ptr);

}