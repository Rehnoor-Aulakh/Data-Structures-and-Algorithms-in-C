#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> reverseQueueFirstKElements(queue<int> q, int k)
{
    int size=q.size();
    if(q.empty() || k>size ||k<=0)
    {
        return q;
    }
    else
    {
        stack<int> st;
        //Put First k elements in stack
        for(int i=1;i<=k;i++)
        {
            st.push(q.front());
            q.pop();
        }
        //Enque the elements from stack and they will be reversed
        for(int i=1;i<=k;i++)
        {
            q.push(st.top());
            st.pop();
        }
        //Dequeue the remaining elements and enqueue them at end
        for(int i=0;i<size-k;i++)
        {
            q.push(q.front());
            q.pop();
        }
        return q;

    }
}

int main()
{
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);

    q=reverseQueueFirstKElements(q,4);
    cout<<"Printing the Queue\n";
    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop();
    }
}