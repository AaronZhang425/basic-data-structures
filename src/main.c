#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "linked_list.h"
#include "queue.h"

int main() {
    struct linked_list *linked_list = new_linked_list();
    
    int num1 = 4;
    int num2 = 6;

    linked_list_add(linked_list, 0, &num1, sizeof(int));
    linked_list_add(linked_list, 1, &num2, sizeof(int));

    int num3 = *((int *) linked_list_get(linked_list, 0));
    int num4 = *((int *) linked_list_get(linked_list, 1));

    printf("Num 3: %d\n", num3);
    printf("Num 4: %d\n", num4);
    
    destroy_linked_list(linked_list);

    return 0;

}