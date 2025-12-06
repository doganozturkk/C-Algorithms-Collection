#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

Queue* queue_create(int capacity) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int) * capacity);
    q->head = 0; q->tail = 0; q->capacity = capacity;
    return q;
}

void queue_enqueue(Queue *q, int val) {
    if (q->tail >= q->capacity) return; // no circular buffer for simplicity
    q->data[q->tail++] = val;
}

int queue_dequeue(Queue *q) {
    if (q->head >= q->tail) return -1;
    return q->data[q->head++];
}

int queue_is_empty(Queue *q) {
    return q->head >= q->tail;
}

void queue_free(Queue *q) {
    free(q->data);
    free(q);
}
