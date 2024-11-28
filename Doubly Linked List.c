#include <stdio.h>
#include <stdlib.h>

// Practicing some Doubly Linked lists and its methods

// Create the node
typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}node;

// Function to create a Node in main
node *create_node(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

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

// Helper function to get user input as an integer
int get_int_input(const char *prompt) {
    char buffer[100];
    int value;
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &value) == 1) {
                return value;
            } else {
                printf("Invalid input. Please enter a valid integer.\n");
            }
        } else {
            printf("Error reading input. Please try again.\n");
        }
    }
}

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
