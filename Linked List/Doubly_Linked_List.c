#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

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
void insertAtBeginning(struct Node **head, int data)
{
    //We will be using Call by Reference in this Tutorial
    //So return type would be void and we will use double pointer to access memory
    struct Node *new;
    new=(struct Node *)malloc(sizeof(struct Node));
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    if(*head==NULL)
    {
        *head=new;
    }
    else
    {
        new->next=*head;
        (*head)->prev=new;
        *head=new;
    }
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *new,*t=*head;
    new=(struct Node *)malloc(sizeof(struct Node));
    while(t->next!=NULL)
    {
        t=t->next;
    }
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if(*head==NULL)
    {
        *head=new;
    }
    else
    {
        t->next=new;
        new->prev=t;
    }
}
void insert(struct Node **head, int data, int position)
{
    struct Node *new,*t=*head;
    new=(struct Node *)malloc(sizeof(struct Node));
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    if(position==1)
    {
        //New should be the first node
        //new.prev==NULL && new.next==*head
        new->prev=NULL;
        new->next=*head;
        *head=new;
        //Update the first element pointer in the called function
    }
    else
    {
        //Take the t pointer to position
        for(int i=1;i<position;i++)
        {
            if(t!=NULL)
            {
                t=t->next;
            }
            else
            {
                printf("Position out of bound");
                return;
            }
        }
        if(t->next)
        {
            new->next=t;
        }
        new->prev=t->prev;
        t->prev->next=new;
        t->prev=new;
        
    }
}
void deleteFrontNode(struct Node **head)
{
    struct Node *t=*head;
    if(*head==NULL)
    {
        printf("List Empty!!!");
        return;
    }
    else
    {
        (*head)=(*head)->next;
        (*head)->prev=NULL;
        free(t);
        return;
    }
}
void deleteLastNode(struct Node **head)
{
    struct Node *t=*head;
    if(*head==NULL)
    {
        printf("List Empty!!!");
        return;
    }
    else
    {
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->prev->next=NULL;
        free(t);
        return;
    }
}
void delete(struct Node **head, int position)
{
    struct Node *t=*head;
    if(*head==NULL)
    {
        printf("List Empty!!!");
        return;
    }
    else if(position==1)
    {
        (*head)=(*head)->next;
        free(t);
        return;
    }
    else
    {   
        for(int i=1;i<position;i++)
        {
            if(t!=NULL)
            t=t->next;
            else
            {
                printf("Position Out of Bound!!!");
                return;
            }
        }
        if(t->next)
        {
            t->next->prev=t->prev;
        }
        t->prev->next=t->next;
        free(t);
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    //Allocate memory for Linked List in heap
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));
    fifth=(struct Node *)malloc(sizeof(struct Node));

    head->data=1;
    head->next=second;
    second->prev=head;
    second->data=2;
    second->next=third;
    third->prev=second;
    third->data=3;
    third->next=fourth;
    fourth->prev=third;
    fourth->data=4;
    fourth->next=fifth;
    fifth->prev=fourth;
    fifth->data=5;
    fifth->next=NULL;
    printf("Doubly Linked List Created\n");
    printData(head);
    printf("Inserting a New Node at Beginning with Value 10\n");
    insertAtBeginning(&head,10);
    printData(head);
    printf("Insert a New Node at End with value 10\n");
    insertAtEnd(&head,10);
    printData(head);
    printf("Insert a New Node at Position 3 with value 10\n");
    insert(&head,10,3);
    printData(head);
    printf("Deleting Front Node with value 10\n");
    deleteFrontNode(&head);
    printData(head);
    printf("Deleting Last Node with value 10\n");
    deleteLastNode(&head);
    printData(head);
    printf("Deleting 2nd Node with value 10\n");
    delete(&head,2);
    printData(head);
}