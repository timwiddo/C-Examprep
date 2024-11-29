#include <stdio.h>
#include "node.h"

void forwardtraversal(node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data); // Print the current node's data
        current = current->next;     // Move to the next node
    }
    printf("\n");
}

void backtraversal(node *tail) {

    node *current = tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}