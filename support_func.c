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

void push_list(List *list, char *format, ...) {
    if (list == NULL) {
        return;
    }

    va_list factor;
    va_start(factor, format);


    List *ptr = list;
    for (; ptr->next != NULL; ++ptr) {
        ptr = ptr->next;
    }
    printf("%s\n", format);
    for (char *form_ptr = format; *form_ptr; ++form_ptr) {
        List *new_node = (List *)malloc(sizeof(List));
        printf("hello %c\n", *form_ptr);
        switch(*form_ptr) {
        case 'd':
            new_node->value_type = INTEGER;
            new_node->value.digit = va_arg(factor, int);
            new_node->next = NULL;
            ptr->next = new_node;
            ptr = ptr->next;
            break;
        case 'r':
            new_node->value_type = REAL;
            new_node->value.real = va_arg(factor, double);
            new_node->next = NULL;
            ptr->next = new_node;
            ptr = ptr->next;
            break;
        case 's':
            new_node->value_type = STRING;
            new_node->value.string = va_arg(factor, char*);
            new_node->next = NULL;
            ptr->next = new_node;
            ptr = ptr->next;
            break;
        default:
            free(new_node);
            
    }
    }
    

    

    va_end(factor);

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
    va_end(factor);
}

void show_string(char* string) {
    for (char *ptr = string; *ptr; ++ptr) {
        printf("%c", *ptr);
    }
    printf("\n");
}

List *new_list(char *format, ...) {
    va_list factor;
    va_start(factor, format);
    var variable;
    List *list = (List *)malloc(sizeof(List));
    List *node_ptr = list;
    list->next = NULL;

    for (char *ptr = format; *ptr; ++ptr) {
        
        switch (*ptr) {
            case 'd':
                variable.digit = va_arg(factor, int);
                push_list(node_ptr, "d", variable);
                node_ptr = node_ptr->next;
                break;
            case 's':
                variable.string = va_arg(factor, char*);
                push_list(node_ptr, "s", variable);
                node_ptr = node_ptr->next;
                break;
            case 'r':
                variable.real = va_arg(factor, double);
                push_list(node_ptr, "r  ", variable);
                node_ptr = node_ptr->next;
                break;
        }
        
        
    }

    va_end(factor);
    return list;
}


void print_list(List *list) {
    for (List *ptr = list; ptr->next != NULL; ++ptr) {
        
        switch(ptr->value_type) {
            case INTEGER:
                printf("%d ", ptr->value.digit);
                break;
            case REAL:
                char *num = format_double(ptr->value.real);
                printf("%s ", num);
                free(num);
                break;
            case STRING:
                printf("%s", ptr->value.string);
                break;
        }
    }
}

void free_list(List *list) {
    List *ptr = list, *prev_ptr;

    for (; ptr->next != NULL; ++ptr) {
        prev_ptr = ptr;
        ptr = ptr->next;
        free(prev_ptr);
    }

    free(ptr);

}