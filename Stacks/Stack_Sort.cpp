#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int> &st, int num)
{
    if(st.empty())
    {
        st.push(num);
    }
    else if(st.top()<num)
    {
        st.push(num);
    }
    else
    {
        int temp=st.top();
        st.pop();
        //Recursive calls
        insertSorted(st, num);
        st.push(temp);
    }
}

void sortStack(stack<int> &st)
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
        sortStack(st);
        //Add the number in sorted way
        insertSorted(st,num);
    }
}

int main()
{
    stack<int> st;
    st.push(5);
    st.push(-2);
    st.push(9);
    st.push(-7);
    st.push(3);
    sortStack(st);
    cout<<"Stack Sorted"<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}