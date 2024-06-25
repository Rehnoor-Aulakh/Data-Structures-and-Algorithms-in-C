#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isOperator(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='%'||x=='^')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int precedence(char x)
{
    if(x=='*' ||x=='/' || x=='%' ||x=='^')
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

string In_to_Po(string infix)
{
    string postfix;
    stack<char> st;
    int i=0,j=0;
    while(i!=infix.length())
    {
        if(!isOperator(infix[i]))
        {
            postfix.push_back(infix[i]);
            i++;
            j++;
        }
        else
        {
            if(!st.empty() && precedence(infix[i])>precedence(st.top()))
            {
                st.push(infix[i]);
                i++;
            }
            else
            {
                postfix.push_back(st.top());
                st.pop();
                j++;
            }
        }
        
    }
    while(!st.empty())
    {
        postfix.push_back(st.top());
        st.pop();
        j++;
    }
    return postfix;
}


int main()
{
    string infix="x+y*z-k";
    cout<<In_to_Po(infix);
}