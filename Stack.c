#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// As always: Array Stack mit push, pop, peek, isfull, isempty

#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

int mystack[STACK_LENGTH];                          //init des Stack Arrays
int top = EMPTY;                                    //Top=-1 denn das erste element würde an Position 0 stehen
                                                    // top is der Pointer auf oberstes Element im Stack

bool push(int value)
{
    if (top >= STACK_LENGTH-1) return false;         //wenn voll kann nix gepushed werden

    top++;                                           //falls nicht, pointe auf next position im array und fülle sie
    mystack[top] = value;
    return true;
}

int pop()
{
    if (top == EMPTY) return STACK_EMPTY;             //wir gehen davon aus dass diese zahl nie auf Stack gepushed wird

    int result = mystack[top];
    top--;
    return result;
}



int main(void)
{
    push(14);
    push(35);
    push(48);

    while (top != EMPTY) {
        printf("%d\n", pop());
    }
}
