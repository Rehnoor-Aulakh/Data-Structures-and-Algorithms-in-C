#include<iostream>
#include<stack>
#include<stdlib.h>
struct Queue
{
    std::stack<int> s1;
    std::stack<int> s2;
};

void enQueue(struct Queue *q, int data)
{
    //Just add the elements into s1 stack
    q->s1.push(data);
}
int deQueue(struct Queue *q)
{
    if(!q->s2.empty())
    {
        int val=q->s2.top();
        q->s2.pop();
        return val;
        
    }
    else
    {
        //Shift all the elements from s1 stack to s2 stack
        while(!q->s1.empty())
        {
            q->s2.push(q->s1.top());
            q->s1.pop();
        }
        int val=q->s2.top();
        q->s2.pop();
        return val;
    }
}


int main()
{
    struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
    enQueue(q,10);
    enQueue(q,20);
    enQueue(q,30);
    enQueue(q,40);
    enQueue(q,50);
    printf("Added Elements to Queue 10,20,30,40,50\n");
    printf("Dequeuing Elements from Queue\n");
    printf("%d \n",deQueue(q));   
    printf("%d \n",deQueue(q));   
    printf("%d \n",deQueue(q));   
    printf("%d \n",deQueue(q));   
    printf("%d \n",deQueue(q));
}