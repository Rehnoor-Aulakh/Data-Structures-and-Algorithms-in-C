#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void printQueue(queue<int> q)
{
    while(!q.empty())
    {
        printf("%d",q.front());
        q.pop();
        if(!q.empty())
        {
            printf("-->");
        }
    }
    printf("\n");
}

queue<int> reverseQueue(queue<int> q)
{
    stack<int> st;
    //Dequeue the elements from the queue and push into stack until queue is empty
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    //After queue is empty, pop the elements from the stack into the queue until the stack is empty
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    //Return the resultant queue at the end
    return q;

}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(3);
    q.push(7);
    q.push(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    printf("-------------Intial Queue--------------\n");
    printQueue(q);
    printf("------------After Reversing------------\n");
    printQueue(reverseQueue(q));
}