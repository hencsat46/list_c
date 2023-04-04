#include "typedefs.h"
#include "support_func.h"
#include <stdio.h>  

void main() {
    

    List *list = new_list("dds", 97, 98, "hi");
    print_list(list);
    free_list(list);

}