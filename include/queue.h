#ifndef QUEUE_H
#define QUEUE_H

struct queue_node{
    void *data;
    struct queue_node *next_node;
};

struct queue {
    struct queue_node *head;
    struct queue_node *tail;  
    uint16_t size;
};

#endif