#include <iostream>
#include <stack>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

std::string infixToPostfix(const std::string& infixExpression) {
    std::string postfixExpression = "";
    std::stack<char> operatorStack;

    for (char c : infixExpression) {
        if (isalnum(c)) {
            postfixExpression += c;
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        } else {
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(c)) {
                postfixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty()) {
        postfixExpression += operatorStack.top();
        operatorStack.pop();
    }

    return postfixExpression;
}

int main() {
    std::string infixExpression = "a+b*c-(d/e+f*g*h)";
    std::string postfixExpression = infixToPostfix(infixExpression);

    std::cout << "Infix: " << infixExpression << std::endl;
    std::cout << "Postfix: " << postfixExpression << std::endl;

    return 0;
}
