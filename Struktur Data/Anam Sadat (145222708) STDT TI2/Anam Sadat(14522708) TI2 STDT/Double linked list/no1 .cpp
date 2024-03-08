#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class SortedDoubleLinkedList {
private:
    Node* head;

public:
    SortedDoubleLinkedList() : head(nullptr) {}

    void insertNode(int newData) {
        Node* newNode = new Node;
        newNode->data = newData;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr || newData < head->data) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
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
                newNode->prev = prev;

                if (current != nullptr) {
                    current->prev = newNode;
                }

                if (prev != nullptr) {
                    prev->next = newNode;
                } else {
                    head = newNode;
                }
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
            if (head != nullptr) {
                head->prev = nullptr;
            }
        } else {
            prev->next = current->next;
            if (current->next != nullptr) {
                current->next->prev = prev;
            }
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
    SortedDoubleLinkedList myList;

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
