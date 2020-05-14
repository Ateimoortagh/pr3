#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;
};

void printMenu()
{
   printf("\n");
   printf("1 ---> Insert Head\n");
   printf("2 ---> Insert Tail\n");
   printf("3 ---> Delete Node\n");
   printf("4 ---> Delete All\n");
   printf("5 ---> Display\n");
   printf("6 ---> Search for a Node\n");
   printf("7 ---> Exit\n");
   printf("\n");
}

void printList(struct Node *node) 
{
   if(!node)
   {
       printf("The List is Empty\n");
       return;
   }
   
   while(node)
   {
       printf("%d ",node->data);
       node=node->next;
   }
   printf("\n");
}

struct Node * insertHead(struct Node *head,int value)
{
   struct Node *node=(struct Node *)malloc(sizeof(struct Node));
   node->data=value;
   node->next=head;
   return node;
}

struct Node * insertTail(struct Node *head,struct Node *tail,int value)
{
   struct Node *node=(struct Node *)malloc(sizeof(struct Node));
   node->data=value;
   if(tail==NULL)
       return node;
   tail->next=node;
   return node;
}

struct Node * deleteNode(struct Node *head,int value)
{
   if(head==NULL)
       return NULL;
   struct Node *node=head,*prev=NULL;
   while(node)
   {
       if(node->data==value)
           break;
       prev=node;
       node=node->next;
   }
   if(prev==NULL)
       return head->next;
   prev->next=node->next;
   return head;
}

struct Node * deleteList(struct Node *node)
{
   if(!node)
       return NULL;
   deleteList(node->next);
   free(node);
   return NULL;
}

void findAnElement(struct Node *node,int value)
{
   while(node)
   {
       if(node->data==value)
       {
           printf("%d does appear in the list\n",value);
           return;
       }
       node=node->next;
   }
   printf("%d does not appear in the list\n",value);
}

int main()
{
   struct Node *head=NULL,*tail=NULL;
   int choice,value;
   while(1)
   {
       printMenu();
       printf("Selection: ");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
               printf("Enter a value: ");
               scanf("%d",&value);
               head=insertHead(head,value);
               if(tail==NULL)
                   tail=head;
               break;
           case 2:
               printf("Enter a value: ");
               scanf("%d",&value);
               tail=insertTail(head,tail,value);
               if(head==NULL)
                   head=tail;
               break;
           case 3:
               printf("Enter a value: ");
               scanf("%d",&value);
               head=deleteNode(head,value);
               break;
           case 4:
               head=deleteList(head);
               break;
           case 5:
               printList(head);
               break;
           case 6:
               printf("Enter a value: ");
               scanf("%d",&value);
               findAnElement(head,value);
               break;
           case 7:
               return 0;
           default:
               printf("Invalid option\n");
               break;
       }
   }
   return 0;
}
