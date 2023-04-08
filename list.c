#include "list.h"
#include "typedefs.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

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

    for (char *form_ptr = format; *form_ptr; ++form_ptr) {
        List *new_node = (List *)malloc(sizeof(List));
        
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
            printf("Type error\n");
            continue;
        }
    
    }
    

    

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
                push_list(node_ptr, "d", va_arg(factor, int));
                node_ptr = node_ptr->next;
                break;
            case 's':
                push_list(node_ptr, "s", va_arg(factor, char*));
                node_ptr = node_ptr->next;
                break;
            case 'r':
                push_list(node_ptr, "r", va_arg(factor, double));
                node_ptr = node_ptr->next;
                break;
            default:
                printf("Type error\n");
                continue;
        }
        
        
    }

    va_end(factor);
    return list;
}


void print_list(List *list) {
    for (List *ptr = list->next; ptr != NULL; ptr = ptr->next) {
        
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
                printf("%s ", ptr->value.string);
                break;
        }
    }
    printf("\n");
}



void free_list(List *list) {
    List *ptr = list;
    List *prev_ptr;

    while (ptr->next != NULL) {
        prev_ptr = ptr;
        ptr = ptr->next;
        free(prev_ptr);
    }
    

    free(ptr);

}

void pop_elem(List *list) {
    List *ptr = list, *prev_ptr;
    while (ptr->next->next != NULL) ptr = ptr->next;
    free(ptr->next);
    ptr->next = NULL;
}