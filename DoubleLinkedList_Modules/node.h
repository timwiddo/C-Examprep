//
// Created by s_widmoser24 on 29.11.2024.
//

#ifndef NODE_H
#define NODE_H

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}node;

node *delete_at_beginning(node *head);
node* delete_last(node *head);
node *delete_at_position(node *head, int position);
node *create_node(int data);
int get_int_input(const char *prompt);
void forwardtraversal(node *head);
void backtraversal(node *tail);
node *insert_at_beginning(node *head, int data);
node *insert_at_end(node *head, int data);
node *insert_at_position(node *head, int data, int position);

#endif //NODE_H
