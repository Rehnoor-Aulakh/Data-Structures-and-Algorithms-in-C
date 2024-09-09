#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isOperator(char x) 
{
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

int precedence(char x) 
{
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return 0;
}


string In_to_Po(string infix) {
    string postfix;
    stack<char> st;
    for (int i = 0; i < infix.length(); i++) 
    {
        char c = infix[i];

        // If the character is an operand, add it to the output string
        if (isalnum(c)) {
            postfix.push_back(c);
        }
        // If the character is '(', push it onto the stack
        else if (c == '(') {
            st.push(c);
        }
        // If the character is ')', pop and output from the stack until '(' is found
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix.push_back(st.top());
                st.pop();
            }
            if (!st.empty()) st.pop(); // pop the '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) 
            {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining operators from the stack
    while (!st.empty()) 
    {
        postfix.push_back(st.top());
        st.pop();
    }

    return postfix;
}

int main() 
{
    string infix = "a+b/c*2-(3-d)*E-(F*G/H)";
    cout << "Postfix expression: " << In_to_Po(infix) << endl;
    return 0;
}
