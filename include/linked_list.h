#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct linked_list_node {
    void *data;
    struct linked_list_node *next_node;
};

struct linked_list {
    struct linked_list *head;
    uint16_t size;
};

#endif