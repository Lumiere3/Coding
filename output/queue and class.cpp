#include <iostream>
using namespace std;

#define MAX 100

class Queue {
private:
    int items[MAX], front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull() {
        if (rear == MAX - 1)
            return true;
        else
            return false;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Antrian penuh!" << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
            items[rear] = value;
        } else {
            rear++;
            items[rear] = value;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong!" << endl;
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Antrian kosong!" << endl;
            return;
        }

        for (int i = front; i <= rear; i++)
            cout << items[i] << " ";
        cout << endl;
    }
};


int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();


    return 0;
}
