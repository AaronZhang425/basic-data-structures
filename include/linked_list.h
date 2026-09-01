#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct linked_list_node {
    void *data;
    struct linked_list_node *next_node;
};

struct linked_list {
    struct linked_list_node *head;
    uint16_t size;
};

struct linked_list_node *get_last_node(struct linked_list *linked_list);

struct linked_list *new_linked_list();

void destory_linked_list(struct linked_list *linked_list);

void destroy_linked_list_node_full(struct linked_list_node *node);

int linked_list_append(
    struct linked_list *linked_list,
    void *data,
    size_t data_size
);

void *linked_list_get(struct linked_list *linked_list, uint32_t target_index);

void linked_list_remove(struct linked_list *linked_list, uint32_t target_index);

int linked_list_add(
    struct linked_list *linked_list,
    uint32_t target_index,
    void *data,
    size_t data_size
);

#endif