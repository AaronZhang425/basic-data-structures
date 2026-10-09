#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct doubly_linked_list_node {
    struct doubly_linked_list_node *prev;
    struct doubly_linked_list_node *next;
    void *data;
};

struct doubly_linked_list {
    struct doubly_linked_list_node *head;
    struct doubly_linked_list_node *tail;
    uint16_t size;
};

struct doubly_linked_list *new_doubly_linked_list();
void destory_doubly_linked_list(struct doubly_linked_list *list);
int doubly_linked_list_add(
    struct doubly_linked_list *list,
    uint16_t target_index,
    void *data,
    size_t data_size
);

#endif