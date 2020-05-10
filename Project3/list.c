
/*
 *list.c Project3
 *Alireza Teimoortagh */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
static Node * Node_construct(int v)
{
Node * n = malloc(sizeof(Node));
n -> value = v;
n -> next = NULL;
return n;
}

Node * List_insert(Node * head, int v)
{
printf("insert %d\n", v);
Node * p = Node_construct(v);
p -> next = head;
return p; 
}

Node * List_search(Node * head, int v)
{
Node * p = head;
while (p != NULL)
{
if ((p -> value) == v)
   {
   return p;
   }
p = p -> next;
}
return p;
}

Node * List_delete(Node * head, int v)
{
printf("delete %d\n", v);
Node * p = head;
if (p == NULL) 
{
return p;
}

if ((p -> value) == v)
{
p = p -> next;
free (head);
return p;
}


Node * q = p -> next;
while ((q != NULL) && ((q -> value) != v))
{

p = p -> next;
q = q -> next;
}
if (q != NULL)
{

p -> next = q -> next;
free (q);
}
return head;
}

void List_destroy(Node * head)
{
while (head != NULL)
{
Node * p = head -> next;
free (head);
head = p;
}
}

void List_print(Node * head)
{
printf("\nPrint list:\n");
while (head != NULL)
{
printf("%d ", head -> value);
head = head -> next;
}
printf("\n\n");
}
Node * List_insert_Last(Node* head, int v)
{
   printf("inserting node %d to the end of the list\n", v);
   Node * p = Node_construct(v);
   Node* node = head;
   if(node == NULL)return p;  
   while(node->next != NULL)
   {
       node = node->next;
   }  
   node->next = p;
   return node;
}
