#include <stdio.h>
#include "sorting/sorting.h"
#include "searching/searching.h"
#include "data_structures/linked_list.h"
#include "data_structures/stack.h"
#include "data_structures/queue.h"
#include "data_structures/binary_tree.h"

int main() {
    printf("--- Sorting Tests ---\n");
    int arr1[] = {5,2,9,1,5,6};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    bubble_sort(arr1, n1);
    printf("Bubble sorted: "); for(int i=0;i<n1;i++) printf("%d ", arr1[i]); printf("\n");

    int arr2[] = {64,25,12,22,11};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    selection_sort(arr2, n2);
    printf("Selection sorted: "); for(int i=0;i<n2;i++) printf("%d ", arr2[i]); printf("\n");

    int arr3[] = {12, 11, 13, 5, 6, 7};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    merge_sort(arr3, 0, n3-1);
    printf("Merge sorted: "); for(int i=0;i<n3;i++) printf("%d ", arr3[i]); printf("\n");

    int arr4[] = {10,7,8,9,1,5};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    quick_sort(arr4, 0, n4-1);
    printf("Quick sorted: "); for(int i=0;i<n4;i++) printf("%d ", arr4[i]); printf("\n");

    printf("\n--- Searching Tests ---\n");
    int sarr[] = {1,3,5,7,9,11};
    int idx = linear_search(sarr, 6, 7);
    printf("Linear search for 7: index=%d\n", idx);
    idx = binary_search(sarr, 6, 5);
    printf("Binary search for 5: index=%d\n", idx);

    printf("\n--- Linked List Test ---\n");
    Node *head = NULL;
    append(&head, 10); append(&head, 20); append(&head, 30);
    print_list(head);
    free_list(head);

    printf("\n--- Stack Test ---\n");
    Stack *s = stack_create(10);
    stack_push(s, 1); stack_push(s, 2); stack_push(s, 3);
    printf("Popped: %d\n", stack_pop(s));
    stack_free(s);

    printf("\n--- Queue Test ---\n");
    Queue *q = queue_create(10);
    queue_enqueue(q, 5); queue_enqueue(q, 6);
    printf("Dequeued: %d\n", queue_dequeue(q));
    queue_free(q);

    printf("\n--- Binary Tree Test ---\n");
    TreeNode *root = NULL;
    root = bt_insert(root, 50);
    bt_insert(root, 30); bt_insert(root, 70); bt_insert(root, 20); bt_insert(root, 40);
    printf("Inorder: "); bt_inorder(root); printf("\n");
    bt_free(root);

    return 0;
}
