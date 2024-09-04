#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    string s="DataStructure";
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        st.push(s[i]);
    }
    string n;
    while(!st.empty())
    {
        n.push_back(st.top());
        st.pop();
    }
    cout<<n;

}
