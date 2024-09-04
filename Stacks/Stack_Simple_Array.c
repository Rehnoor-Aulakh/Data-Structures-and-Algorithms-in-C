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
    S->array= malloc(S->capacity * sizeof(int));

    printf("Stack Created Successfully\n");
    return S;
}

int isEmpty(struct Stack *S)
{
    return (S->top==-1);
    //if(S->top==-1) it will return 1 that means stack is empty otherwise 0
}
int size(struct Stack *S)
{
    return (S->top+1);
}

int isFull(struct Stack *S)
{
    return (S->capacity == S->top+1);
}

void push(struct Stack *S, int data)
{
    if(isFull(S))
    {
        printf("Stack Overflow!!!\n");
    }
    else
    {
        //Increment top and store the value of data at that position
        S->array[++S->top]=data;
    }
}
int pop(struct Stack *S)
{
    //If stack is empty, return INT_MIN
    if(isEmpty(S))
    {
        printf("Stack is Empty!!!\n");
        return INT_MIN;
    }
    else
    {
        //Remove the topmost element of stack and decrement top after that
        return (S->array[S->top--]);
    }
}
int peek(struct Stack *S)
{
    //If Stack is Empty, return INT_MIN
    if(isEmpty(S))
    {
        return INT_MAX;
    }
    else
    {
        //Just return the topmost element
        return (S->array[S->top]);
    }
}
void deleteStack(struct Stack *S)
{
    if(S)
    {
        if(S->array)
        {
            free(S->array);
            free(S);
        }
    }
}

void printStack(struct Stack *st)
{
    if(isEmpty(st))
    {
        return;
    }
    int num=pop(st);
    printStack(st);
    printf("%d\n",num);
}

int main()
{
    int capacity=15;
    //Create stack stk of capacity 15
    struct Stack *stk= createStack(capacity);
    for(int i=1;i<=15;i++)
    {
        push(stk,i);
        printf("Pushed Element is %d\n",i);
    }
    printf("Top Element of Stack is %d\n",peek(stk));
    printf("Stack Size is %d\n",size(stk));
    printf("------------------------------\n");
    printStack(stk);
    printf("------------------------------\n");

    for(int i=1;i<=15;i++)
    {
        printf("Popped element is %d\n",pop(stk));
    }
    if(isEmpty(stk))
    {
        printf("Stack is Empty");        
    }
    else
    {   
        printf("Stack Not Empty");
    }
    deleteStack(stk);
    return 0;
}