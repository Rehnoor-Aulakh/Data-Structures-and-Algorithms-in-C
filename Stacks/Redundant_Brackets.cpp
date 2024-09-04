#include<iostream>
#include<stack>
using namespace std;
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='('||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            bool isRedundant=true;
            while(st.top()!='(')
            {
                //check if the top element is an operator
                if(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/')
                {
                    //This bracket is not redundant
                    isRedundant=false;
                }
                st.pop();
            }
            if(isRedundant)
            {
                return true;
            }
            //Remove the opening bracket for next checking
            st.pop();
            
        }

    }
    return false;
}

int main()
{
    string s="(c*(a+b))";
    cout<<findRedundantBrackets(s);
}