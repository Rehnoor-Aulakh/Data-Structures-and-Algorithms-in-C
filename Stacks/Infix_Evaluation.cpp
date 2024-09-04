#include <iostream>
#include <stack>
#include <string>
#include<math.h>
using namespace std;

bool isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '('|| x=='^');
}

int precedence(char x) {
    if (x == '*' || x == '/') {
        return 2;
    } else if (x == '+' || x == '-') {
        return 1;
    } else {
        return 0;
    }
}

int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int infixEvaluation(string infix) {
    stack<int> operands;
    stack<char> operators;

    for (int i = 0; i < infix.length(); i++) {
        if (isspace(infix[i])) {
            continue;
        }

        if (isdigit(infix[i])) {
            int num = 0;
            while (i < infix.length() && isdigit(infix[i])) {
                num = num * 10 + (infix[i] - '0');
                i++;
            }
            i--;
            operands.push(num);
        } else if (infix[i] == '(') {
            operators.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();

                operands.push(applyOperation(a, b, op));
            }
            operators.pop();
        } else if (isOperator(infix[i])) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(infix[i])) {
                char op = operators.top();
                operators.pop();

                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();

                operands.push(applyOperation(a, b, op));
            }
            operators.push(infix[i]);
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();

        int b = operands.top();
        operands.pop();
        int a = operands.top();
        operands.pop();

        operands.push(applyOperation(a, b, op));
    }

    return operands.top();
}

int main() {
    string infix = "1+(2*3)-5";
    cout << infixEvaluation(infix) << endl; // Output: 2
    return 0;
}