#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

//Now same with a linked list

#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

int mystack[STACK_LENGTH];
int top = EMPTY;

//Node Def
typedef struct node {
    int value;
    struct node *next;
} node;

typedef node * stack;

bool push(stack *mystack, int value)
{
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL) return false; // edgecase of RAM being full?

    newnode->value = value; // dereferencing?
    newnode->next = *mystack;
    *mystack = newnode;
    return true;
}

int pop(stack *mystack)
{
    if (*mystack == NULL) return STACK_EMPTY;

    int result = (*mystack)->value;   // = mystack[top]; now we grab the value from the top node by dereferencing it with "->" instad of array[max_position]
    node *tmp = *mystack;           //schnappen wert -> pointen ihn an(mit hilfspointer) ->
    *mystack = (*mystack)->next;          //lassen pointer jetz aufs nächste element dereferencen(zeigen)
    free(tmp);                  //speicher freimachen an adresse
    return result;
}



int main(void)
{
    stack s1, s2, s3 = NULL;
    push(&s1,14);
    push(&s2,13);
    push(&s2,45);
    push(&s2,643);
    push(&s3,4);
    push(&s3,63);
    push(&s1,88);
    push(&s3,1);
    int t;
    while ((t = pop(&s2)) != STACK_EMPTY) {
        printf("%d\n", t);
    }
}
