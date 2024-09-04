#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int front, rear;
    int capacity;
    int size;
    int *arr;
}

//Create an empty Queue

struct Queue *createQueue(int capacity)
{
    struct Queue *q=malloc(sizeof(struct Queue));
    q->capacity=capacity;
    q->front=q->rear=-1;
    q->size=0;
    q->arr=malloc(q->capacity*sizeof(int));
    return q;
}

int size(struct Queue *q)
{
    return q->size;
}

int front(struct Queue *q)
{
    return q->front;
}
int rear(struct Queue *q)
{
    return q->rear;

}

int isEmpty(struct Queue *q)
{
    return (q->size==0);
}

int isFull(struct Queue *q)
{
    return (q->siz==q->capacity);
}

void resizeQueue(struct Queue *q)
{
    int size=q->capacity;
    q->capacity=q->capacity*2;
    q->arr=realloc(q->arr,q->capacity*sizeof(int));

    if(q->front>q->rear)
    {
        for(int i=0;i<q->front;i++)
        {
            q->arr[i+size]=q->arr[i];
        }
        q->rear=q->rear+size;
    }
}

void enQueue(struct Queue *q, int data)
{
    if(isFull())
    {
        resizeQueue(q);
    }
    q->rear=(q->rear+1)%q->capacity;
    q->arr[q->rear]=data;
    if(q->front==-1)
    {
        q->front=q->rear;
    }
    q->size+=1;
}