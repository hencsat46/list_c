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

typedef enum types {
    INTEGER,
    REAL,
    STRING,
} types;

typedef struct List {
    var value;
    struct List *next;
    types value_type;
} List;


#endif