#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "deque.h"

struct deque *new_deque(void) {
    return calloc(1, sizeof(struct deque));

}

// TODO: Implement
void destory_deque(struct deque *deque) {

}

void destory_deque_node_full(struct deque_node *list) {
    free(list->data);
    free(list);

}

// TODO: Implement
int add_to_head_deque(struct deque *list, void *data, size_t data_size) {
    struct deque_node *new_node = calloc(1, sizeof(struct deque_node));

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

    new_node->prev = NULL;
    new_node->next = list->head;

    if (!list->head) {
        list->head->prev = new_node;

    }
    
    list->head = new_node;

    list->size++;

    return 0;

}

// TODO: Implement
void *poll_head_deque(struct deque *list) {
    return NULL;

}

// TODO: Implement
int add_to_tail_deque(struct deque *list, void *data, size_t data_size) {
    return 0;

}

// TODO: Implement
void *poll_tail_deque(struct deque *list) {
    return NULL;

}