#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Queue
{
    int front, rear;
    int size;
    int capacity;
    int *arr;
};

//Create an empty Queue

struct Queue *createQueue(int capacity)
{
    //Allocate memory to queue
    struct Queue *Q=malloc(sizeof(struct Queue));
    //Capacity is the maximum size of queue array
    Q->capacity=capacity;
    //Front and rear are the indices of front and rear elements of queue
    Q->front=Q->rear=-1;
    //Size is the number of elements stored in the queue
    Q->size=0;
    //Allocate memory to array i.e capacity times sizeof(int)
    Q->arr=malloc(Q->capacity*sizeof(int));
    return Q;
}

//Return Queue Size
int size(struct Queue *q)
{
    return q->size;
}

//Return Front Element of Queue
int front(struct Queue *q)
{
    return q->arr[q->front];

}

//Return Rear Element of Queue
int rear(struct Queue *q)
{
    return q->arr[q->rear];
}

//Check if Queue is Empty
int isEmpty(struct Queue *q)
{
    return (q->size==0);
}

//Check if Queue is Full
int isFull(struct Queue *q)
{
    return (q->size==q->capacity);
}

//Add Elements to Queue

void enQueue(struct Queue *q, int data)
{
    if(isFull(q))
    {
        printf("\nQueue Overflow");
    }
    else
    {
        q->rear=(q->rear+1)%q->capacity;
        q->arr[q->rear]=data;
        //If initially front is -1, then increment front so that queue can be dequeued next time
        if(q->front==-1)
        {
            q->front=q->rear;
        }
        //After enqueuing, the size of queue increases by 1
        q->size+=1;
    }
}

//Delete Elements from Queue

int deQueue(struct Queue *q)
{
    int data=INT_MIN;   //Element which does not exist in queue
    //dequeue is not possible in empty queue
    if(isEmpty(q))
    {
        printf("\nQueue is Empty!!!");
        return data;
    }
    //Element to be deleted from the queue is the front element
    data=q->arr[q->front];
    //If front and rear indices are same, that means q is empty, so dequeuing is not possible, make size 0
    if(q->front==q->rear)
    {
        q->front=q->rear=-1;
        q->size=0;
    }
    else
    {
        //Increment front
        q->front=(q->front+1)%q->capacity;
        //Decrement the size of queue after dequeuing
        q->size-=1;
    }
    return data;
}

void delete(struct Queue *q)
{
    if(q)
    {
        if(q->arr)
        {
            free(q->arr);
        }
        free(q);
    }
}

int main()
{
    //Initializing Queue
    struct Queue *q;
    q=createQueue(10);
    //Adding elements in queue
    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,3);
    enQueue(q,4);
    enQueue(q,5);
    enQueue(q,6);

    //Printing the size of queue
    printf("\n%d ",size(q));

    //Front Element of Queue
    printf("\n%d",front(q));
    //Rear Element of Queue
    printf("\n%d\n",rear(q));

    //Dequeuing Elements from the queue
    while(!isEmpty(q))
    {
        printf("%d ",deQueue(q));
    }
    enQueue(q,12);
    enQueue(q,15);

    //Printing Size of Queue
    printf("\n%d",size(q));

    //Printing Front and Rear elements of queue
    printf("\n%d",front(q));
    printf("\n%d",rear(q));

    //Removing Queue
    delete(q);
    
}

