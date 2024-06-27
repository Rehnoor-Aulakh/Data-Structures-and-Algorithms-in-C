#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }
    else
    {
        int num=st.top();
        st.pop();
        //Recursive calls
        insertAtBottom(st,x);
        //Push the element back into the stack
        st.push(num);
    }
}

void reverse(stack<int> &st)
{
    if(st.empty())
    {
        return;
    }
    else
    {
        int num=st.top();
        st.pop();
        //Recursive Calls
        reverse(st);
        insertAtBottom(st,num);

    }
}




int main()
{
    stack<int> st;
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(7);
    st.push(6);

    reverse(st);
    cout<<"Stack Reversed"<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}