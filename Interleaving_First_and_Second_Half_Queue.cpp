#include<iostream>
#include<queue>
using namespace std;

queue<int> interleave(queue<int> q)
{
    int size=q.size()/2;
    std::queue<int> q1,q2;
    for(int i=0;i<size;i++)
    {
        q1.push(q.front());
        q.pop();
    }
    for(int i=0;i<size;i++)
    {
        q2.push(q.front());
        q.pop();
    }
    bool flag=true;
    for(int i=0;i<size*2;i++)
    {
        if(flag)
        {
            q.push(q1.front());
            q1.pop();
        }
        else
        {
            q.push(q2.front());
            q2.pop();
        }
        flag=!flag;
    }
    return q;
}

int main()
{
    std::queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    q=interleave(q);
    cout<<"Printing Elements of Queue\n";
    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop();
    }
}