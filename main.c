#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include "consts.h"

typedef union {
    int digit;
    uint8_t* string;
    double real;
} var;

void show_string(uint8_t* string) {
    for (; *string; ++string) {
        printf("%c", *string);
    }
    printf("\n");
}



void format_double(double num) {
    
    uint8_t *old_str = (uint8_t *)malloc(64);
    
    sprintf(old_str, "%f", num);
    printf("%s\n", old_str);
    bool dot_state = FALSE, find_zero = FALSE;
    uint8_t *ptr_null;
    
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
    printf("%d\n", find_zero);
    uint8_t *new_str;
    if (find_zero) {
        
        
        new_str = (uint8_t *)malloc((size_t)(ptr_null - old_str));
        for (uint8_t *ptr = old_str, *new_ptr = new_str; ptr < ptr_null; ++ptr, ++new_ptr) {
            *new_ptr = *ptr;
        }
        show_string(new_str);
    }
    free(new_str);
    free(old_str);
    
    
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
    
    format_double(144.11);
    //printf("%.2f\n", 0.2 + 0.3);

}