#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Stack* stack_create(int capacity) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (int*)malloc(sizeof(int) * capacity);
    s->top = -1;
    s->capacity = capacity;
    return s;
}

void stack_push(Stack *s, int val) {
    if (s->top + 1 >= s->capacity) return; // no resize for simplicity
    s->data[++s->top] = val;
}

int stack_pop(Stack *s) {
    if (s->top == -1) return -1;
    return s->data[s->top--];
}

int stack_is_empty(Stack *s) {
    return s->top == -1;
}

void stack_free(Stack *s) {
    free(s->data);
    free(s);
}
