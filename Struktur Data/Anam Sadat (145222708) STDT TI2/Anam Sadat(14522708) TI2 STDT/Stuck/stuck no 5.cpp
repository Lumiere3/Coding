#include <iostream>
#include <stack>

int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: return 0;
    }
}

int evaluatePostfix(const std::string& postfixExpression) {
    std::stack<int> operandStack;

    for (char c : postfixExpression) {
        if (isalnum(c)) {
            operandStack.push(c - '0');
        } else {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            int result = performOperation(c, operand1, operand2);
            operandStack.push(result);
        }
    }

    return operandStack.top();
}

int main() {
    std::string postfixExpression = "23*5+";
    int result = evaluatePostfix(postfixExpression);

    std::cout << "Postfix: " << postfixExpression << std::endl;
    std::cout << "Hasil evaluasi: " << result << std::endl;

    return 0;
}
