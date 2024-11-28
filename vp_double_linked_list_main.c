#include <stdio.h>
#include <stdlib.h>

// Create the node
typedef struct node {
    void *data;  // Store a pointer to any type of data
    struct node *next;
    struct node *prev;
} node;

// Function to create a Node in main
node *create_node(void *data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

// Function to traverse the list forward and print the data (for demonstration, cast it to int*)
void forwardtraversal(node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    node *current = head;
    while (current != NULL) {
        printf("%d ", *((int *)current->data)); // Cast the void* data back to int* for printing
        current = current->next;
    }
    printf("\n");
}

// Function to traverse the list backward and print the data
void backtraversal(node *tail) {
    node *current = tail;
    while (current != NULL) {
        printf("%d ", *((int *)current->data)); // Cast the void* data back to int* for printing
        current = current->prev;
    }
    printf("\n");
}

// Insert at the beginning of the list
node *insert_at_beginning(node *head, void *data) {
    node *newnode = create_node(data);
    newnode->next = head;
    if (head != NULL) {
        head->prev = newnode;
    }
    return newnode;
}

// Insert at the end of the list
node *insert_at_end(node *head, void *data) {
    node *newnode = create_node(data);
    if (head == NULL) {
        return newnode;
    }
    node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newnode;
    newnode->prev = current;
    return head;
}

// Insert at a specific position in the list
node *insert_at_position(node *head, void *data, int position) {
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
    for (int i = 1; i < position - 1 && current != NULL; ++i) {
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

// Delete node at the beginning of the list
node *delete_at_beginning(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Delete node at the end of the list
node *delete_last(node *head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->prev->next = NULL;
    free(curr);
    return head;
}

// Delete node at a specific position
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

    if (current->prev)
        current->prev->next = current->next;

    if (current->next)
        current->next->prev = current->prev;

    if (head == current)
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

// Helper function to get user input as a void pointer
void* get_void_pointer_input(const char *prompt) {
    int *ptr = (int *)malloc(sizeof(int));  // Assume we are working with integers for simplicity
    *ptr = get_int_input(prompt);  // Get the value as an integer and store it in the pointer
    return ptr;
}

int main() {
    node *head = NULL;
    int choice, position;

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
            head = insert_at_beginning(head, get_void_pointer_input("Enter value to insert at the beginning: "));
            break;
        case 2:
            head = insert_at_end(head, get_void_pointer_input("Enter value to insert at the end: "));
            break;
        case 3:
            position = get_int_input("Enter the position to insert at: ");
            head = insert_at_position(head, get_void_pointer_input("Enter value to insert: "), position);
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
                free(temp->data);  // Free the dynamically allocated data
                free(temp);
            }
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

