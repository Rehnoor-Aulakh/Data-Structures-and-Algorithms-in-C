// https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void interleave(queue<int> &q)
{
    int size=q.size();
    //Create a stack
    stack<int> st;
    //Dequeue first half elements of q and push into stack
    //intially q: 4 7 11 20 5 9, st: empty
    for(int i=0;i<size/2;i++)
    {
        st.push(q.front());
        q.pop();
    }
    //q: 20 5 9, st: 11(T) 7 4
    //Now pop the elements from the stack and enqueue into queue
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    //q: 20 5 9 11 7 4, st: empty
    //Now dequeue first half of queue and enqueue it back
    for(int i=0;i<size/2;i++)
    {
        q.push(q.front());
        q.pop();
    }
    // q: 11 7 4 20 5 9, st: empty
    //Again push half of queue into stack
    for(int i=0;i<size/2;i++)
    {
        st.push(q.front());
        q.pop();
    }
    //q: 20 5 9, st: 4(T) 7 11
    //Now interleave the queue
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    //q: 4 20 7 5 11 9, is the desired queue
}

int main()
{
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);
    interleave(q);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}