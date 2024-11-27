#include <stdio.h>
#include <stdlib.h>



/*
    Entwickeln Sie eine Liste, die void Pointer in einer bestimmten Reihenfolge speichert,
    so dass sie eine beliebige Datenstruktur speichern kann. Die Liste sollte mindestens
    folgende Funktionen haben.
        a. Add – Fügt ein Element am Ende der Liste hinzu.
        b. Get – Gibt ein Element an einer bestimmten Position zurück.
        c. Contains – Überprüft, ob ein Element in der Liste gespeichert ist und gibt die
           Position zurück.
        d. Remove – Entfernt das Element an der angegebenen Position.
        e. IsEmpty – Überprüft, ob die Liste leer ist.
        f. Size – Überprüft, wie viele Elemente in der Liste gespeichert sind.
*/


typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR
} DataType;

typedef struct node {
    void *ptr;           // Pointer auf die Daten
    DataType type;       // Datentyp
    struct node *next;   // Zeiger auf den nächsten Knoten
} node;

// Globale Kopfzeiger-Variable
node *head = NULL;

// Funktion, um einen neuen Knoten hinzuzufügen
void add(void *data, DataType type) {
    // Initialisierung des neuen Knotens
    node *new_node = (node *)malloc(sizeof(node));
    if (!new_node) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    new_node->ptr = data; // Datenpointer speichern
    new_node->type = type; // Typ des Daten speichern
    new_node->next = NULL;

    // Wenn die Liste leer ist
    if (head == NULL) {
        head = new_node;
        return;
    }

    // Liste traversieren, um ans Ende zu gelangen
    node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node; // Füge neuen Knoten ans Ende an
}

void get(int position) {
    int count = 0;
    node *current = head;

    // Traverse bis zur gewünschten Position
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    // Ungültige Position
    if (current == NULL) {
        fprintf(stderr, "Error: Position %d out of bounds or list is empty.\n", position);
        return;
    }

    // Typ prüfen und Wert ausgeben
    printf("Value at position %d: ", position);
    if (current->type == TYPE_INT) {
        printf("%d\n", *(int *)(current->ptr));
    } else if (current->type == TYPE_FLOAT) {
        printf("%.2f\n", *(float *)(current->ptr));
    } else if (current->type == TYPE_CHAR) {
        printf("%c\n", *(char *)(current->ptr));
    } else {
        printf("Unknown type\n");
    }
}

// Funktion, um die Liste auszugeben
void printlist(node *head) {
    node *current = head;
    while (current != NULL) {
        // Ausgeben je nach Typ
        if (current->type == TYPE_INT) {
            printf("%d ", *(int *)(current->ptr));
        } else if (current->type == TYPE_FLOAT) {
            printf("%.2f ", *(float *)(current->ptr));
        } else if (current->type == TYPE_CHAR) {
            printf("%c ", *(char *)(current->ptr));
        } else {
            printf("Unknown type ");
        }
        current = current->next;
    }
    printf("\n"); // Neue Zeile für Lesbarkeit
}

int contains(void *data, DataType type) {

//TODO

}


int main(void) {
    int a = 42, b = 98, c = 25;
    float d = 3.14;
    char e = 'X';

    // Daten zur Liste hinzufügen
    add(&a, TYPE_INT);
    add(&b, TYPE_INT);
    add(&c, TYPE_INT);
    add(&d, TYPE_FLOAT);
    add(&e, TYPE_CHAR);

    // Liste ausgeben
    printlist(head);
    get(3);

    return 0;
}
