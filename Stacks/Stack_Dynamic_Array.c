//Logic here is that whenever the stack is full, we will reallocate the stack array to double its size
//So time complexity will be O(N)

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack *createStack(int capacity)
{
    struct Stack *S= malloc(sizeof(struct Stack));
    S->capacity=capacity;
    S->top=-1;
    S->array=malloc(S->capacity*sizeof(int));
    return S;
}
int isEmpty(struct Stack *S)
{
    if(S->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int size(struct Stack *S)
{
    return (S->top+1);
}
int isFull(struct Stack *S)
{
    if(S->top+1==S->capacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void doubleStack(struct Stack *S)
{

    S->capacity=S->capacity*2;
    S->array=realloc(S->array,S->capacity*sizeof(int));
}
void push(struct Stack *S, int data)
{
    if(isFull(S))
    {
        doubleStack(S);
    }
    //Then increment top and add data to it
    S->array[++S->top]=data;
}
int pop(struct Stack *S)
{
    if(isEmpty(S))
    {
        printf("Stack is Empty!!!\n");
        return INT_MIN;
    }
    else
    {
        //Return top element and then decrement top
        return(S->array[S->top--]);
    }
}
int peek(struct Stack *S)
{
    if(isEmpty(S))
    {
        printf("Stack is Empty!!!\n");
        return INT_MIN;
    }
    return (S->array[S->top]);
}
void deleteStack(struct Stack *S)
{
    if(S)
    {
        if(S->array)
        {
            free(S);
        }
    }
}
int main()
{
    struct Stack *S=createStack(4);
    //Creating Stack of capacity 4
    printf("Dynamic Array Stack Created\n");
    for(int i=1;i<=16;i++)
    {
        push(S,i);
        printf("Inserted Element is %d\n",peek(S));
    }
    for(int i=1;i<=16;i++)
    {
        printf("Removed Element is %d\n",pop(S));
    }
    deleteStack(S);
    printf("Stack Deleted Successfully");
}