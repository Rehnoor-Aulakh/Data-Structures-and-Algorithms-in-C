#include<stdio.h>
#include<stdlib.h>
//Creating Linked List
struct Node
{
    int data;
    struct Node *next;
};
//Printing Linked List
void printData(struct Node *head)
{
    struct Node *t=head;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;

    }
    printf("\n");
}
//Calculating Size of Linked List
int length(struct Node *head)
{
    struct Node *t=head;
    int count=0;
    while(t!=NULL)
    {
        count++;
        t=t->next;
    }
    return count;
}
struct Node *insertAtBeginning(struct Node *head, int data)
{
    //Create a new Node with parameter data
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    if(head==NULL)
    {
        return temp;
    }
    else
    {
        temp->next=head;
        head=temp;
        return head;
    }
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=NULL;
    struct Node *t=head;
    if(head==NULL)
    {
        //If head is NULL, then temp will be the head node
        head=temp;
        return head;
    }
    else
    {
        //Take t to the last node and set its next to temp
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=temp;
        return head;
    }
}

struct Node *insertAtGivenPosition(struct Node *head, struct Node *new, int n)
{
    struct Node *t=head;
    //Point t to n-1 Node
    for(int i=1;i<n-1;i++)
    {
        t=t->next;
    }
    //Now this is the predicessor Node, new->next should be connected with pred->next
    new->next=t->next;
    t->next=new;
    return head;
}

struct Node *deleteFirst(struct Node *head)
{
    struct Node *t=head;
    t=t->next;
    head->next=NULL;
    head=t;
    return head;
}
struct Node *deleteLast(struct Node *head)
{
    struct Node *t=head;
    while(t->next->next!=NULL)
    {
        t=t->next;
    }
    t->next=NULL;
    return head;
}

struct Node *delete(struct Node *head, int n)
{
    struct Node *t=head;
    for(int i=1;i<n-1;i++)
    {
        t=t->next;
    }
    t->next=t->next->next;
    return head;
}
struct Node *deleteLinkedList(struct Node *head)
{
    struct Node *t=head,*iterator;
    while(t!=NULL)
    {
        iterator=t;
        t=t->next;
        free(iterator);
        iterator=t;
    }
    head=NULL;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //Allocate memory for nodes in the linked list in heap
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));
    
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=fourth;
    fourth->data=4;
    fourth->next=NULL;
    printData(head);
    printf("Length Of Linked List is %d\n",length(head));
    printf("Inserting 10 at Beginnning\n");
    printData(head=insertAtBeginning(head,10));
    printf("Inserting 10 At the End\n");
    printData(insertAtEnd(head,10));
    struct Node *new;
    new=(struct Node *)malloc(sizeof(struct Node));
    new->data=10;
    new->next=NULL;
    printf("Inserting 10 At 3rd Position\n");
    printData(insertAtGivenPosition(head,new,3));
    printf("Deleting First Position\n");
    printData(head=deleteFirst(head));
    printData(head);
    printf("Deleting Last Position\n");
    printData(head=deleteLast(head));
    printf("Deleting 10 At 2nd Position\n");
    printData(head=delete(head,2));
    printf("Deleting Linked List\n");
    head=deleteLinkedList(head);
    if(head==NULL)
    {
        printf("Linked List Deleted Successfully\n");
    }

}


