#include<stdio.h>
#include<stdlib.h>

//Assuming stack is created

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
