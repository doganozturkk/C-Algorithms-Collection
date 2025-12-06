#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue {
    int *data;
    int head;
    int tail;
    int capacity;
} Queue;

Queue* queue_create(int capacity);
void queue_enqueue(Queue *q, int val);
int queue_dequeue(Queue *q);
int queue_is_empty(Queue *q);
void queue_free(Queue *q);

#endif
