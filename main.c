#include "typedefs.h"
#include "list.h"
#include <stdio.h>

void main() {
    
    List *list = new_list("ddsd", 97, 98, "hi", 55);
    pop_elem(list);
    print_list(list);
    printf("%d\n", list_length(list));
    insert_elem(list, 4, 'd', (var)6);
    print_list(list);
    free_list(list);
    // a
}