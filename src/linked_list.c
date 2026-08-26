#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "linked_list.h"

struct linked_list *new_link_list() {
    return calloc(1, sizeof(struct linked_list));

}

// Also frees the data pointer.
void destory_linked_list(struct linked_list *linked_list) {
    struct linked_list_node *working_node = linked_list->head;
    struct linked_list_node *next_node = working_node->next_node;

    free(linked_list);
    linked_list = NULL;

    while (next_node) {
        free(working_node->data);
        free(working_node);
        
        working_node = next_node;
        
        next_node = working_node->next_node;

    }

    free(working_node);

}