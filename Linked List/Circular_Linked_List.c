#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printData(struct Node *head)
{
    struct Node *current=head;
    if(head==NULL)
    {
        return;
    }
    else
    {
        do
        {
            printf("%d ",current->data);
            current=current->next;
        } while (current!=head);
        printf("\n");
        return;
        
    }
}

int length(struct Node *head)
{
    struct Node *current=head;
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        int count=0;
        do
        {
            current=current->next;
            count++;
        } while (current!=head);
        return count;
    }
}
void insertAtEnd(struct Node **head, int data)
{
    struct Node *current=*head,*new;
    new=(struct Node *)malloc(sizeof(struct Node));
    new->data=data;
    //Since new would be the last element, it should point to head
    //Also if head is NULL, the new.next will be null
    new->next=(*head);
    if(*head==NULL)
    {
        *head=new;
        return;
    }
    while (current->next!=(*head))
    {
        current=current->next;
    }
    //Now at this position of current, current.next points to head
    //change current.next to new
    current->next=new;
    return;
}
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *t=*head,*new;
    new=(struct Node *)malloc(sizeof(struct Node));
    new->data=data;
    new->next=(*head);
    if(*head==NULL)
    {
        *head=new;
        return;
    }
    else
    {
        while(t->next!=(*head))
        {
            t=t->next;
        }
        t->next=new;
        //Only Difference between Inserting at End and at Beginning is that we have to update head pointer to new node
        (*head)=new;
        return;
    }
}
void deleteLastNode(struct Node **head)
{
    struct Node *t=*head, *current=*head;
    if(*head==NULL)
    {
        printf("List Empty!!!");
        return;
    }
    while(current->next!=*head)
    {
        t=current;
        current=current->next;
        //In this way, current will be at the last position and t at last-1 position
    }
    t->next=(*head);
    free(current);
    return;
}
void deleteFrontNode(struct Node **head)
{
    struct Node *t=*head,*current=*head;
    if(*head==NULL)
    {
        printf("List Empty!!!");
        return;
    }
    while(current->next!=(*head))
    {
        current=current->next;
    }
    //Current is now at the last position, set current.next to t.next
    current->next=t->next;
    (*head)=(*head)->next;
    free(t);
    return;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));
    fifth=(struct Node *)malloc(sizeof(struct Node));

    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=fourth;
    fourth->data=4;
    fourth->next=fifth;
    fifth->data=5;
    //For Circular Linked List, next of last element points to head
    fifth->next=head;
    printf("Length of Circular Linked List is %d\n",length(head));
    printData(head);
    printf("Inserting 10 At End\n");
    insertAtEnd(&head,10);
    printData(head);
    printf("Inserting 20 At Beginning\n");
    insertAtBeginning(&head,20);
    printData(head);
    printf("Deleting Last Node with value 10\n");
    deleteLastNode(&head);
    printData(head);
    printf("Deleting Front Node with value 20\n");
    deleteFrontNode(&head);
    printData(head);  

}