#include "bool_type.h"
#include "format_double.h"
#include <stdlib.h>

char* format_double(double num) {
    
    char *old_str = (char *)malloc(64);
    
    sprintf(old_str, "%f", num);
    
    bool dot_state = FALSE, find_zero = FALSE;
    char *ptr_null;
    
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
    
    char *new_str;
    if (find_zero) {
        
        int size = ptr_null - old_str + 1;
        new_str = (char *)malloc(size);
        
        for (char *ptr = old_str, *new_ptr = new_str; ptr < ptr_null; ++ptr, ++new_ptr) {
            *new_ptr = *ptr;
        }
        *(new_str + size - 1) = '\0';
        
    }

    free(old_str);
    old_str = NULL;
    return new_str;    
}