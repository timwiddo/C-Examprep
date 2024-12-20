#include <stdio.h>
#include <stdlib.h>

// Definition des Knotens
typedef struct Node {
    void* data;            // Zeiger auf beliebige Daten
    struct Node* next;     // Zeiger auf den nächsten Knoten
} Node;

// Definition der Liste
typedef struct {
    Node* head;   // Zeiger auf den ersten Knoten
    int size;     // Größe der Liste
} VoidPointerList;

// Funktion, um eine neue Liste zu erstellen
VoidPointerList* createList() {
    VoidPointerList* list = (VoidPointerList*)malloc(sizeof(VoidPointerList));
    list->head = NULL;
    list->size = 0;
    return list;
}

// Funktion, um ein Element am Ende der Liste hinzuzufügen
void add(VoidPointerList* list, void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    list->size++;
}

// Funktion, um ein Element an einer bestimmten Position zu bekommen
void* get(VoidPointerList* list, int position) {
    if (position < 0 || position >= list->size) {
        return NULL;  // Ungültige Position
    }
    
    Node* temp = list->head;
    for (int i = 0; i < position; i++) {
        temp = temp->next;
    }
    return temp->data;
}

// Funktion, um zu überprüfen, ob ein Element in der Liste existiert
int contains(VoidPointerList* list, void* data) {
    Node* temp = list->head;
    int position = 0;
    
    while (temp != NULL) {
        if (temp->data == data) {
            return position;  // Element gefunden, gebe Position zurück
        }
        temp = temp->next;
        position++;
    }
    
    return -1;  // Element nicht gefunden
}

// Funktion, um ein Element an einer bestimmten Position zu entfernen
void removeAt(VoidPointerList* list, int position) {
    if (position < 0 || position >= list->size) {
        return;  // Ungültige Position
    }
    
    Node* temp = list->head;
    if (position == 0) {
        list->head = temp->next;
        free(temp);
    } else {
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
    
    list->size--;
}

// Funktion, um zu überprüfen, ob die Liste leer ist
int isEmpty(VoidPointerList* list) {
    return list->size == 0;
}

// Funktion, um die Größe der Liste zu bekommen
int size(VoidPointerList* list) {
    return list->size;
}

// Funktion, um die Liste zu löschen und den Speicher freizugeben
void freeList(VoidPointerList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
}

// Testprogramm
int main() {
    VoidPointerList* list = createList();
    
    int a = 5, b = 10, c = 15;
    
    add(list, &a);
    add(list, &b);
    add(list, &c);
    
    printf("Size of list: %d\n", size(list));
    printf("Element at position 1: %d\n", *(int*)get(list, 1));
    printf("Contains 10 at position: %d\n", contains(list, &b));
    
    removeAt(list, 1);
    printf("Size of list after removal: %d\n", size(list));
    
    freeList(list);
    
    return 0;
}
