#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> nextSmallerElement(vector<int> arr, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.top() < arr[i])
        {
            ans[i] = (st.top());
            st.push(arr[i]);
        }
        else
        {
           while(st.top()>=arr[i])
           {
               st.pop();
           }
           //At the end top element must be smaller than arr[i]
           ans[i]=st.top();
           st.push(arr[i]);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(8);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(25);
    arr = nextSmallerElement(arr, arr.size());
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}