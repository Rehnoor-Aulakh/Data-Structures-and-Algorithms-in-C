#include<iostream>
#include<stack>
using namespace std;

void deleteMiddle(stack<int> &s, int count, int size)
{
    if(count==size/2)
    {
        s.pop();
        return;
    }
    else
    {
        int num=s.top();
        s.pop();
        deleteMiddle(s,count+1,size);
        s.push(num);
    }
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(9);
    s.push(12);
    s.push(8);
    s.push(4);

    deleteMiddle(s,0,5);
    cout<<"Printing the Stack After Deleting the middle element"<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}