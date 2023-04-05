#include "typedefs.h"
#include "support_func.h"
#include <stdio.h>  

void main() {
    

    List *list = new_list("ddsd", 97, 98, "hi", 55);
    print_list(list);
    pop_elem(list);
    print_list(list);
    free_list(list);

}