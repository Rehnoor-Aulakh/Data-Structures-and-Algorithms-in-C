//Convert infix expression to prefix expression
//Algorithm:
//1. Reverse the infix expression
//2. Replace '(' with ')' and vice versa
//3. Now apply the infix to postfix algorithm
//4. Reverse the resultant expression to obtain the prefix expression

#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isOperator(char x)
{
    return (x=='+'||x=='-'||x=='*'||x=='/'||x=='%'||x=='^');
}
int precedence(char x)
{
    if(x=='^')
    {
        return 3;
    }
    else if(x=='*' || x=='/' || x=='%')
    {
        return 2;
    }
    else if(x=='+' || x=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string infixToPostfix(string &infix)
{
    stack<char> st;
    string ans;
    int size=infix.size();
    for(int i=0;i<size;i++)
    {
        char x=infix[i];
        if(x=='(')
        {
            st.push(x);
        }
        else if(isOperator(x))
        {
            if(!st.empty() && precedence(x)>precedence(st.top()))
            {
                st.push(x);
            }
            else
            {
                while(!st.empty() && (precedence(st.top())>=precedence(x)))
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(x);
            }
        }
        else if(x==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                ans.push_back(st.top());
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
                //pop ( from the stack
            }
        }
        else
        {
            ans.push_back(x);
        }
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

string infixToPrefix(string &infix)
{
    //reverse the string
    string reversed;
    for(int i=infix.size()-1;i>=0;i--)
    {
        //replace '(' with ')' and vice versa
        if(infix[i]=='(')
        {
            infix[i]=')';
        }
        else if(infix[i]==')')
        {
            infix[i]='(';
        }
        reversed.push_back(infix[i]);
    }
    //Now apply the infix to postfix algorithm
    string postfix=infixToPostfix(reversed);
    //reverse the postfix to obtain prefix
    string ans;
    for(int i=postfix.size()-1;i>=0;i--)
    {
        ans.push_back(postfix[i]);
    }
    return ans;
}

int main()
{
    string s="(A+B^C)*D+E^5";
    cout<<infixToPrefix(s)<<endl;

}