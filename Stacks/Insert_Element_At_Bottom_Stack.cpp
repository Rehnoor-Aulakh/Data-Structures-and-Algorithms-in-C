#include<iostream>
#include<stack>
using namespace std;

void insertAtBottomRecursive(stack<int> &st, int x)
{
    //Recursion is prefered because space complexity will become O(1) as compared to O(N) in loop
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
        insertAtBottomRecursive(st,x);
        //Push the element back into the stack
        st.push(num);
    }
}


stack<int> insertAtBottom(stack<int> &st, int x)
{
    stack<int> temp;
    while(!st.empty())
    {
        temp.push(st.top());
        st.pop();

    }
    st.push(x);
    while(!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
    return st;
}

int main()
{
    stack<int> st;
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(8);

    // st=insertAtBottom(st,2);
    cout<<"Element Inserted At Bottom"<<endl;
    // while(!st.empty())
    // {
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    insertAtBottomRecursive(st,2);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}