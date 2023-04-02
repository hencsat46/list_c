#ifndef TYPEDEFS_H
#define TYPEDEFS_H

typedef enum bool {
    TRUE = 1,
    FALSE = 0,
} bool;

typedef union {
    int digit;
    char* string;
    double real;
} var;

typedef struct List {
    var elem;
    struct List *next;
} List;

#endif