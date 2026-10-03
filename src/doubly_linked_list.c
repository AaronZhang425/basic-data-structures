#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "doubly_linked_list.h"

struct doubly_linked_list *new_doubly_linked_list() {
    return calloc(1, sizeof(struct doubly_linked_list) );

}

void destory_doubly_linked_list(struct doubly_linked_list *list) {
    struct doubly_linked_list_node *node = list->head;

    while (node) {
        free(node->data);
        node->next;

        free(node->prev);

    }

    free(list);

}