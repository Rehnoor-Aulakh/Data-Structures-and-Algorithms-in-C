//Most widely used in Real life
//Built in stack in java and c++ is linked list stack
//No need to give capacity at the beginning
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

struct Stack *createStack()
{
    struct Stack *S;
    S=malloc(sizeof(struct Stack));
    S->top=NULL;
    return S;
}

void push(struct Stack *S, int data)
{
    //Add the new element at the top/front of the linked list
    struct Node *temp;
    temp=malloc(sizeof(struct Node));
    temp->data=data;
    //Insert temp at the top by assigning its next to S.top
    temp->next=S->top;
    //Update the top of stack by assigning it temp node
    S->top=temp;
}

int size(struct Stack *S)
{
    //We can improve the time complexity of size() by adding size in struct Stack and updating it every time we push or pop
    struct Node *temp=S->top;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

int isEmpty(struct Stack *S)
{
    return (S->top==NULL);
}

int pop(struct Stack *S)
{
    //Reassign the top node of stack the next node
    struct Node *temp=S->top;
    if(isEmpty(S))
    {
        printf("Stack is Empty!!!");
        return INT_MIN;
    }
    int data=temp->data;
    S->top=S->top->next;
    free(temp);
    return data;
}

int peek(struct Stack *S)
{
    if(isEmpty(S))
    {
        printf("Stack is Empty!!!");
        return INT_MIN;
    }
    return S->top->data;
}

void deleteStack(struct Stack *S)
{
    struct Node *temp,*p;
    p=S->top;
    while(p!=NULL)
    {
        temp=p->next;
        p=p->next;
        free(temp);
    }
    free(S);
}

int main()
{
    struct Stack *S=createStack();
    printf("Created Linked List Stack\n");
    for(int i=1;i<=10;i++)
    {
         push(S,i);
        printf("Inserted Element is %d\n",peek(S));
    }
    for(int i=1;i<=10;i++)
    {
        printf("Removed Element is %d\n",pop(S));
    }
    deleteStack(S);
}
