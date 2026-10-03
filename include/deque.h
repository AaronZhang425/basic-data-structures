#ifndef DEQUE_H
#define DEQUE_H

struct deque_node {
    struct deque_node *prev;
    struct deque_node *next;
    void *data;
};

struct deque {
    struct deque_node *head;
    struct deque_node *tail;
    uint16_t size;
};


#endif