#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct AdvancedStack
{
    struct Stack *elementStack;
    struct Stack *minStack;
};

struct Stack *createStack(int capacity)
{
    struct Stack *st= malloc(sizeof(struct Stack));
    st->capacity=capacity;
    st->top=-1;
    st->array=malloc(sizeof(st->capacity*sizeof(int)));
    printf("Stack Created Successfully\n");
    return st;
}

struct Stack *createAdvancedStack(int capacity)
{
    struct AdvancedStack *st=malloc(sizeof(struct AdvancedStack));
    st->elementStack=createStack(capacity*sizeof(int));
    st->minStack=createStack(capacity*sizeof(int));
    return st;
}

int isEmpty(struct Stack *st)
{
    return (st->top==-1);
}

int isFull(struct Stack *st)
{
    if(st->top+1==st->capacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct Stack *st, int data)
{
    if(isFull(st))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->array[++st->top]=data;
    }
}

int pop(struct Stack *st)
{
    if(isEmpty(st))
    {
        return INT_MIN;
    }
    else
    {
        return st->array[st->top--];
    }
}

int peek(struct Stack *st)
{
    if(isEmpty(st))
    {
        return INT_MIN;
    }
    else
    {
        return st->array[st->top];
    }
}

int isEmptyA(struct AdvancedStack *st)
{
    return (st->elementStack->top==-1);
}

int isFullA(struct AdvancedStack *st)
{
    if(st->elementStack->top+1==st->elementStack->capacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void pushA(struct AdvancedStack *st, int data)
{
    if(isFullA(st))
    {
        printf("Stack Overflow\n");
        return;
    }
    push(st->elementStack,data);
    //check if the previous min top is larger than data
    if (isEmpty(st->minStack) || data <= peek(st->minStack)) {
        push(st->minStack, data);
    } else {
        push(st->minStack, peek(st->minStack));
    }
}

int popA(struct AdvancedStack *st)
{
    if(isEmptyA(st))
    {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    //pop from both the stacks
    pop(st->minStack);
    return pop(st->elementStack);
}

int peekA(struct AdvancedStack *st)
{
    if(isEmptyA(st))
    {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    return peek(st->elementStack);
}

int getMinimum(struct AdvancedStack *st)
{
    if(isEmptyA(st))
    {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    return (peek(st->minStack));
}

void deleteStack(struct Stack *st)
{
    if(st)
    {
        if(st->array)
        {
            free(st->array);
            free(st);
        }
    }
}

void deleteStackA(struct AdvancedStack *st)
{
    if(st)
    {
        deleteStack(st->elementStack);
        deleteStack(st->minStack);
        free(st);
    }
}

void printStack(struct Stack *st)
{
    if(isEmpty(st))
    {
        return;
    }
    else
    {
        int num=pop(st);
        printf("%d\n",num);
        printStack(st);
        push(st,num);
    }
}

int main()
{
    struct AdvancedStack *st=createAdvancedStack(5);
    pushA(st,2);
    pushA(st,6);
    pushA(st,4);
    pushA(st,1);
    pushA(st,5);
    //now print the stack
    printStack(st->elementStack);
    printf("------------------------\n");
    printStack(st->minStack);
}
