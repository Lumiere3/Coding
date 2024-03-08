#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int newData) {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            std::cout << "Stack kosong" << std::endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void displayStack() {
        Node* current = top;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
};

int main() {
    Stack myStack;

    myStack.push(5);
    myStack.push(3);
    myStack.push(8);
    myStack.displayStack();

    myStack.pop();
    myStack.displayStack();

    return 0;
}
