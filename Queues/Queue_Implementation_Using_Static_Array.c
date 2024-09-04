#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Queue *q)
{
    if(q->r==q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void enqueue(struct Queue *q, int val)
{
    if(isFull(q))
    {
        printf("Queue Overflow");
    }
    else
    {
        q->r++;
        q->arr[q->r]=val;

    }
}

int dequeue(struct Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty");
        return -1;
    }
    else
    {
        q->f++;
        return q->arr[q->f];
    }
}

int main()
{
    struct Queue q;
    q.size=5;
    q.f=q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
    if(isEmpty(&q))
    {
        printf("Queue is Empty\n");
    }

    //Enqueue few elements into the queue
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);

    //Dequeuing Elements
    printf("%d ",dequeue(&q));
    printf("%d ",dequeue(&q));
}