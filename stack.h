#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    int *data;
    int top;
    int capacity;
} Stack;

Stack* stack_create(int capacity);
void stack_push(Stack *s, int val);
int stack_pop(Stack *s);
int stack_is_empty(Stack *s);
void stack_free(Stack *s);

#endif
