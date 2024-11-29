#include <stdio.h>
#include <stdlib.h>
#include "node.h"

node *delete_at_beginning(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *temp = head;
    head = head->next;
    if (head->next != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

node* delete_last(node *head) {

    // Corner cases
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // Traverse to the last node
    node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    // Update the previous node's next pointer
    curr->prev->next = NULL;

    // Delete the last node
    free(curr);

    // Return the updated head
    return head;
}

node *delete_at_position(node *head, int position) {
    if (head == NULL) {
        return NULL;
    }
    node *current = head;

    for (int i = 1; i < position && current != NULL; ++i) {
        current = current->next;
    }
    if (current == NULL) {
        return NULL;
    }

    if(current -> prev)
        current->prev->next = current->next;

    if(current -> next)
        current->next->prev = current->prev;

    if(head == current)
        head = current->next;

    free(current);
    return head;
}
