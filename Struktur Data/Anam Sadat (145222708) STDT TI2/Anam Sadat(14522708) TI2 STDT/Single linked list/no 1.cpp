#include <iostream>

struct Node {
    int data;
    Node* next;
};

class SortedLinkedList {
private:
    Node* head;

public:
    SortedLinkedList() : head(nullptr) {}

    void insertNode(int newData) {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = nullptr;

        if (head == nullptr || newData < head->data) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            Node* prev = nullptr;

            while (current != nullptr && newData > current->data) {
                prev = current;
                current = current->next;
            }

            if (current != nullptr && newData == current->data) {
                std::cout << "Simpul sudah ada (duplikat)" << std::endl;
                delete newNode;
            } else {
                newNode->next = current;
                prev->next = newNode;
            }
        }
    }

    void deleteNode(int targetData) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && targetData != current->data) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Simpul tidak ditemukan" << std::endl;
            return;
        }

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }

    void displayList() {
        Node* current = head;

        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
};

int main() {
    SortedLinkedList myList;

    myList.insertNode(5);
    myList.insertNode(3);
    myList.insertNode(8);
    myList.insertNode(3);  // duplikat
    myList.insertNode(7);
    myList.displayList();

    myList.deleteNode(3);
    myList.displayList();

    return 0;
}
