#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isOperator(char x)
{
    return (x=='+'||x=='-'||x=='*'||x=='/'||x=='%'||x=='^');
}

string postfixToInfix(string &postfix)
{
    int size=postfix.size();
    stack<string> st;
    for(int i=0;i<size;i++)
    {
        char x=postfix[i];
        if(isalnum(x))
        {
            //if it is a character, push into stack
            st.push(string(1,x));
        }
        if(!st.empty() && isOperator(x))
        {
            string second=st.top();
            st.pop();
            string first=st.top();
            st.pop();
            string temp="("+first+x+second+")";
            st.push(temp);
        }
    }
    return st.top();
}

int main()
{
    string postfix="abc-+de-fg-h+/*";
    cout<<postfixToInfix(postfix);
}