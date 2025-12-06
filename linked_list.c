#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* create_node(int value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void append(Node **head, int value) {
    Node *new_node = create_node(value);
    if (!*head) { *head = new_node; return; }
    Node *tmp = *head;
    while (tmp->next) tmp = tmp->next;
    tmp->next = new_node;
}

void print_list(Node *head) {
    Node *tmp = head;
    while (tmp) {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void free_list(Node *head) {
    Node *tmp = head;
    while (tmp) {
        Node *next = tmp->next;
        free(tmp);
        tmp = next;
    }
}
