#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
    //No need for capacity because it is dynamic
};

struct Queue *createQueue()
{
    struct Queue *q;
    struct Node *t;
    q=malloc(sizeof(struct Queue));
    t=malloc(sizeof(struct Node));
    q->front=q->rear=NULL;
    return q;
}

//Return Queue Size
int size(struct Queue *q)
{
    if(q->front==NULL && q->rear==NULL)
    {
        return 0;
    }
    else
    {
        int count=0;
        struct Node *t=q->front;
        while(t!=q->rear)
        {
            count++;
            t=t->next;
        }
        count++;
        return count;
    }
}

//Return Front Element of Queue
int front(struct Queue *q)
{
    return q->front->data;
}

//Return Rear Element of Queue
int rear(struct Queue *q)
{
    return q->rear->data;
}

//Check if Queue is Empty or not
int isEmpty(struct Queue *q)
{
    return (q->front==NULL);
}

void enQueue(struct Queue *q, int val)
{
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    t->data=val;
    t->next=NULL;
    if(q->front==NULL)
    {
        q->front=q->rear=t;
    }
    else
    {
        //Add the t node next to rear
        q->rear->next=t;
        //Now move the rear pointer to its next because size of queue has increased
        q->rear=q->rear->next;
    }
}

//Remove an Element from Queue

int deQueue(struct Queue *q)
{
    if(q->front==NULL)
    {
        printf("Queue is empty!!!\n");
        return 0;
    }
    else
    {
        //Move the front pointer to its next and free and node
        struct Node *t=q->front;
        q->front=q->front->next;
        return t->data;
        free(t);
    }
}

//Print the Queue

void printQueue(struct Queue *q)
{
    struct Node *t=q->front;
    if(q->front==NULL && q->rear==NULL)
    {
        printf("Queue is Empty!!!");
        return;
    }
    while(t!=NULL)
    {
        printf("%d",t->data);
        t=t->next;
        if(t!=NULL)
        printf("-->");
    }
    printf("\n");
}

//Delete the Queue
void deleteQueue(struct Queue *q)
{
    struct Node *t;
    while(q->front)
    {
        t=q->front;
        q->front=q->front->next;
        free(t);
    }
    free(q);
    printf("Queue Deleted Successfully\n");
}

int main()
{
    struct Queue *q;
    q=createQueue();
    //Adding Elements in Queue
    enQueue(q,1);
    enQueue(q,3);
    enQueue(q,7);
    enQueue(q,5);
    enQueue(q,10);
    //Printing the Queue
    printQueue(q);
    printf("Size of Queue is %d\n",size(q));
    //Printing Front and Rear Elements of Queue
    printf("Front Element of Queue is %d\n",front(q));
    printf("Rear Element of Queue is %d\n",rear(q));
    //Removing Elements from Queue
    while(!isEmpty(q))
    {
        printf("Removed Element is %d\n",deQueue(q));
    }
    if(isEmpty(q))
    {
        printf("Queue is Empty!!!\n");
    }
    printf("Adding New Values to Queue\n");
    enQueue(q,10);
    enQueue(q,15);
    enQueue(q,20);
    enQueue(q,30);
    printQueue(q);
    deleteQueue(q);

}
