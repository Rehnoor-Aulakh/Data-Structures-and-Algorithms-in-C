#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Stack
{
    char top;
    int capacity;
    char *array;
};

struct Stack *createStack(int capacity)
{
    struct Stack *S= malloc(sizeof(struct Stack));

    S->capacity=capacity;
    S->array= malloc(S->capacity * sizeof(char));

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

void push(struct Stack *S, char data)
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
int priority(char x)
{
    if(x=='(')
    {
        return 0;
    }
    else if(x=='+' || x=='-')
    {
        return 1;
    }
    else if(x=='*' || x=='/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
int isOperator(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='('||x==')')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int infixToPostfix(char expression[])
{
    char *e,x;
    //create a stack of capacity 5
    struct Stack *st=createStack(5);

    e=expression;
    while(*e!='\0')
    {
        if(!isOperator(*e))
        {
            printf("%c",*e);
        }
        else if(*e=='(')
        {
            push(st,*e);
        }
        else if(*e==')')
        {
            
            while((x=pop(st))!='(')
            {
                
                printf("%c",x);
            }
        }
        else
        {
            while(priority(peek(st))>=priority(*e))
            {
                printf("%c",pop(st));
            }
            push(st,*e);
        }
        e++;
    }
    while(!isEmpty(st))
    {
        printf("%c",pop(st));
    }


}

int main()
{
    infixToPostfix("(a+(b*(d+2)))");
}