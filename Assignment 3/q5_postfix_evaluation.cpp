#include<iostream>
#include<stack>
#include<string>
using namespace std;

int isOperator(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
    {
        return 1;
    }
    else{
        return 0;
    }
}

int postfixEvaluation(string postfix)
{
    stack<int> st;
    for(int i=0;i<postfix.length();i++)
    {
        //if the element from the postfix expression is a digit, push it into the stack
        if(!isOperator(postfix[i]))
        {
            st.push(postfix[i]-'0');
        }
        else
        {
            //if the element is an operator, remove two elements from the stack and apply the operation between them
            int second=st.top();
            st.pop();
            int first=st.top();
            st.pop();
            switch(postfix[i])
            {
                case '+': st.push(first+second);
                break;
                case '-': st.push(first-second);
                break;
                case '*': st.push(first*second);
                break;
                case '/': st.push(first/second);
                break;
            }
        }
    }
    //At the end only one element will be left in the stack, which will be our answer
    return st.top();
}

int main()
{
    string postfix="123*+5-";
    cout<<postfixEvaluation(postfix);
}
