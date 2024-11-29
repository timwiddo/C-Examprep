#include <stdio.h>
#include "node.h"

node *insert_at_beginning(node *head, int data) {
    node *newnode = create_node(data);
    newnode->next = head; // Point new node's next to the current head
    if (head != NULL) {
        head->prev = newnode; // Update the current head's previous pointer
    }
    return newnode; // The new node becomes the head
}

node *insert_at_end(node *head, int data) {
    node *newnode = create_node(data);
    if (head == NULL) {
        return newnode; // If the list is empty, the new node becomes the head
    }
    node *current = head;
    while (current->next != NULL) {
        current = current->next; // Traverse to the last node
    }
    current->next = newnode; // Link the last node to the new node
    newnode->prev = current; // Update the new node's previous pointer
    return head; // Head remains unchanged
}

node *insert_at_position(node *head, int data, int position) {
    node *newnode = create_node(data);
    if (position == 1) {
        newnode->next = head;
        if (head != NULL) {
            head->prev = newnode;
        }
        head = newnode;
        return head;
    }
    node *current = head;
    for (int i = 1; i < position-1 && current != NULL; ++i) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Position out of range\n");
        return head;
    }

    newnode->prev = current;
    newnode->next = current->next;
    current->next = newnode;

    if (newnode->next != NULL) {
        newnode->next->prev = newnode;
    }
    return head;

}
