#include <stdio.h>
#include <stdlib.h>
#include "node.h"


// Practicing some Doubly Linked lists and its methods

int main() {
    node *head = NULL;
    int choice, data, position;

    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at position\n");
        printf("5. Display forward\n");
        printf("6. Exit\n");
        choice = get_int_input("Enter your choice: ");

        switch (choice) {
        case 1:
            data = get_int_input("Enter the value to insert at the beginning: ");
            head = insert_at_beginning(head, data);
            break;
        case 2:
            data = get_int_input("Enter the value to insert at the end: ");
            head = insert_at_end(head, data);
            break;
        case 3:
            data = get_int_input("Enter the value to insert: ");
            position = get_int_input("Enter the position to insert at: ");
            head = insert_at_position(head, data, position);
            break;
        case 4:
            position = get_int_input("Enter the position to delete: ");
            head = delete_at_position(head, position);
            break;
        case 5:
            printf("Linked List: ");
            forwardtraversal(head);
            break;
        case 6:
            printf("Exiting...\n");
            // Free the list before exiting
            while (head != NULL) {
                node *temp = head;
                head = head->next;
                free(temp);
            }
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

