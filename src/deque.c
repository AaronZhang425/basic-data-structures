#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

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