#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

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

/*void format_double(double num) {
    num = 1.2;
    uint8_t *temp_str;
    sprintf(temp_str, "%f", num);
    int is_end = 0;
     for (;*temp_str != '.';++temp_str, ++new_str) {
         *new_str = *temp_str;
     }
    show_string(new_str);
    
}*/

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
    double hi = 1.2;
    //format_double(1.2);
    uint8_t *str;
    sprintf(str, "%f", hi);
    show_string(str);
}