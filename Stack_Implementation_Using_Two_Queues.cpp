#include<iostream>
#include<queue>
using namespace std;

struct Stack
{
    std::queue<int> q1;
    std::queue<int> q2;
};

void push(struct Stack *st,int data)
{
    if(st->q1.empty())
    {
        //Push the data to s2
        st->q2.push(data);
    }
    else
    {
        st->q1.push(data);
    }
}

int pop(struct Stack *st)
{
    int i,size;
    if(st->q2.empty())
    {
        size=st->q1.size();
        i=0;
        while(i<size-1)
        {
            //Dequeue the elements from queue q1 and enque it in q2 until only one elment remains in q1 which we will return 
            st->q2.push(st->q1.front());
            st->q1.pop();
            i++;
        }
        int val=st->q1.front();
        st->q1.pop();
        return val;
    }
    else
    {
        size=st->q2.size();
        //Push the elements in q1
        i=0;
        while(i<size-1)
        {
            st->q1.push(st->q2.front());
            st->q2.pop();
            i++;
        }
        int val=st->q2.front();
        st->q2.pop();
        return val;
    }
}

int main()
{
    struct Stack *st=(struct Stack *)malloc(sizeof(struct Stack));
    printf("Adding Elements in Stack 10,20,30,40,50\n");
    push(st,10);
    push(st,20);
    push(st,30);
    push(st,40);
    push(st,50);
    printf("Removing Elements from stack\n");
    printf("%d ",pop(st));
    printf("%d ",pop(st));
    printf("%d ",pop(st));
    printf("%d ",pop(st));
    printf("%d ",pop(st));
}