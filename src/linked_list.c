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

struct linked_list *new_linked_list() {
    struct linked_list *new_linked_list = calloc(1, sizeof(struct linked_list));
    return new_linked_list;

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
        
        next_node = next_node->next_node;

    }

    free(working_node->data);
    free(working_node);

}

// Free the node in the heap and the data
void destroy_linked_list_node_full(struct linked_list_node *node) {
    free(node->data);
    free(node);

}

int linked_list_append(
    struct linked_list *linked_list,
    void *data,
    size_t data_size
) {
    struct linked_list_node *new_node = calloc(
        1,
        sizeof(struct linked_list_node)
    );

    void *data_copy = calloc(1, data_size);

    if (!data_copy) {
        return -1;

    }

    memcpy(data_copy, data, data_size);

    new_node->data = data_copy;
    new_node->next_node = NULL;

    struct linked_list_node *final_node = get_last_node(linked_list);

    final_node->next_node = new_node;

    linked_list->size++;

    return 0;

}

void *linked_list_get(struct linked_list *linked_list, uint32_t target_index) {
    if (
        target_index < 0
        || target_index >= linked_list->size
        || !linked_list->size
    ) {
        return NULL;

    }
    
    uint32_t current_index = 0;
    struct linked_list_node *node = linked_list->head;

    while (node && current_index < target_index) {
        node = node->next_node;
        current_index++;    

    }
    
    return node ? node->data : NULL;

}

void linked_list_remove(struct linked_list *linked_list, uint32_t target_index) {
    if (target_index >= linked_list->size) {
        return;

    }

    struct linked_list_node **node = &(linked_list->head);
    struct linked_list_node *removed_node;

    uint32_t current_index = 0;

    while ((*node) && current_index < target_index) {
        node = &((*node)->next_node);
        current_index++;

    }

    removed_node = (*node);
    *node = removed_node->next_node;

    destroy_linked_list_node_full(removed_node);

    linked_list->size--;

}

int linked_list_add(
    struct linked_list *linked_list,
    uint32_t target_index,
    void *data,
    size_t data_size
) {
    if (target_index > linked_list->size) {
        return -1;

    }

    void *data_copy = calloc(1, data_size);

    if (!data_copy) {
        return -1;

    }

    memcpy(data_copy, data, data_size);

    struct linked_list_node *new_node = calloc(
        1,
        sizeof(struct linked_list_node)
    );

    new_node->data = data_copy;

    struct linked_list_node **node = &(linked_list->head);

    uint32_t current_index = 0; 
    
    while ((*node) && current_index < target_index) {
        node = &((*node)->next_node);
        current_index++;
            
    }

    new_node->next_node = *node;
    *node = new_node;
    
    linked_list->size++;

    return 0;

}