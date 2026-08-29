#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "linked_list.h"

struct linked_list_node *get_last_node(struct linked_list *linked_list) {
    struct linked_list_node *node = linked_list->head->next_node;

    while (node) {
        node = node->next_node;

    }

    return node;

}

int new_link_list(struct linked_list **linked_list) {
    struct linked_list *new_link_list = calloc(1, sizeof(struct linked_list));
    
    if (!new_link_list) {
        return -1;

    }

    *linked_list = new_link_list;
    
    return 0;

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

int append_node(struct linked_list *linked_list, void *data, size_t size) {
    struct linked_list_node *new_node = calloc(
        1,
        sizeof(struct linked_list_node)
    );

    void *data_copy = calloc(1, size);

    if (!data_copy) {
        return -1;

    }

    memcpy(data_copy, data, size);

    new_node->data = data_copy;
    new_node->next_node = NULL;

    struct linked_list_node *final_node = get_last_node(linked_list);

    final_node->next_node = new_node;

    return 0;

}

void *linked_list_get(struct linked_list *linked_list, uint32_t target_index) {
    uint32_t current_index = 0;
    struct linked_list_node *node = linked_list->head;

    while (node && current_index < target_index) {
        node = node->next_node;
        current_index++;    

    }
    
    return node ? node->data : NULL;

}