//
// Created by s_widmoser24 on 29.11.2024.
//
#include "node.h"
#include <stdio.h>
#include <stdlib.h>


// Function to create a Node in main
node *create_node(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}