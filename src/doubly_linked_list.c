#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "doubly_linked_list.h"

struct doubly_linked_list *new_doubly_linked_list() {
    return calloc(1, sizeof(struct doubly_linked_list));

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

int add(
    struct doubly_linked_list *list,
    uint32_t target_index,
    void *data,
    size_t data_size
) {
    if (target_index > list->size) {
        return -1;

    }

    struct doubly_linked_list_node *new_node = calloc(
        1,
        sizeof(struct doubly_linked_list_node)
    );

    if (!new_node) {
        return -1;

    }

    void *data_copy = calloc(1, data_size);

    if (!data_copy) {
        free(new_node);
        return -1;

    }

    struct doubly_linked_list_node **current_node = &list->head;
    uint32_t current_index = 0;

    while(current_index < target_index) {
        // TODO: implement adding the new node

        current_index++;

    }

    list->size++;

    return 0;

}