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

#endif