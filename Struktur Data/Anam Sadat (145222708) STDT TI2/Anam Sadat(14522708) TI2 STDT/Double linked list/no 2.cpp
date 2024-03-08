#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int newData) {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            std::cout << "Queue kosong" << std::endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            rear = nullptr;
        }

        delete temp;
    }

    void displayQueue() {
        Node* current = front;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(5);
    myQueue.enqueue(3);
    myQueue.enqueue(8);
    myQueue.displayQueue();

    myQueue.dequeue();
    myQueue.displayQueue();

    return 0;
}
