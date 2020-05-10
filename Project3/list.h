/*
 * list.h Project3
 * Alireza Teimoortagh */

#ifndef LIST_H
#define LIST_H
typedef struct listnode
{
   struct listnode * next;
   int value;
} Node;

Node * List_insert(Node * head, int v);

Node * List_search(Node * head, int v);

Node * List_delete(Node * head, int v);

void List_destroy(Node * head);

void List_print(Node * head);

Node * List_insert_Last(Node* head, int v);

#endif
