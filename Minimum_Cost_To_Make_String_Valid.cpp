#include<iostream>
#include<stack>
#include<string>
using namespace std;

int findMinimumCost(string s) 
{
    int length=s.length();
    if(length%2!=0)
    {
        //Odd case cannot be corrected
        return -1;
    }
    stack<char> st;
    //Remove the valid part from the string
    for(int i=0;i<length;i++)
    {
        if(s[i]=='{')
        {
            st.push(s[i]);
        }
        else if(!st.empty() && s[i]=='}' && st.top()=='{')
        {
            st.pop();
        }
        else if(st.empty() || st.top()!='{')
        {
            st.push(s[i]);
        }
    }
    // while(!st.empty())
    // {
    //     cout<<st.top()<<' ';
    //     st.pop();
    // }
    //Now count the number of { and } in stack
    int a=0,b=0;
    while(!st.empty())
    {
        if(st.top()=='{')
        {
            a+=1;
        }
        else if(st.top()=='}')
        {
            b+=1;
        }
        st.pop();
    }
    //At the end answer will be given by (a+1)/2+(b+1)/2
    return ((a+1)/2)+((b+1)/2);
}

int main()
{
    string s="}}}}";
    cout<<findMinimumCost(s);
}