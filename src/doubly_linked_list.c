#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "doubly_linked_list.h"

struct doubly_linked_list *new_doubly_linked_list(void) {
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

// TODO: Implement
void *doubly_linked_list_get(
    struct doubly_linked_list *list,
    uint16_t target_index
) {
    return NULL;

}

int doubly_linked_list_add(
    struct doubly_linked_list *list,
    uint16_t target_index,
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

    memcpy(data_copy, data, data_size);

    new_node->data = data_copy;

    struct doubly_linked_list_node *current_node = list->head;
    struct doubly_linked_list_node *prev_node = NULL;

    uint32_t current_index = 0;

    while (!current_node && current_index < target_index) {
        prev_node = current_node;
        current_node = current_node->next;
        current_index++;

    }

    // TODO: Handle adding to the very end

    if (!current_node) {
        list->head = new_node;
        new_node->prev = NULL;

    } else {
        prev_node->next = new_node;
        new_node->prev = prev_node;

        current_node->prev = new_node;
        new_node->next = current_node;

    }

    list->size++;

    return 0;

}

int doubly_linked_list_remove(
    struct doubly_linked_list *list,
    uint16_t index
) {
    

}