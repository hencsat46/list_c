#include "typedefs.h"
#include "list.h"


void main() {
    

    List *list = new_list("ddsd", 97, 98, "hi", 55);
    pop_elem(list);
    print_list(list);
    free_list(list);
    // a
}