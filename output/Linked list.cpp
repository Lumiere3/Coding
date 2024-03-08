#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    private:
        Node* head;
    public:
        LinkedList() {
            head = NULL;
        }
        
        void insert(int val) {
            Node* new_node = new Node;
            new_node->data = val;
            new_node->next = head;
            head = new_node;
        }
        
        void traverse() {
            Node* ptr = head;
            while (ptr != NULL) {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
        
        void search(int val) {
            Node* ptr = head;
            while (ptr != NULL) {
                if (ptr->data == val) {
                    cout << "Data ditemukan!" << endl;
                    return;
                }
                ptr = ptr->next;
            }
            cout << "Data tidak ditemukan!" << endl;
        }
        
        void deleteNode(int val) {
            Node* ptr = head;
            Node* prev = NULL;
            
            while (ptr != NULL && ptr->data != val) {
                prev = ptr;
                ptr = ptr->next;
            }
            
            if (ptr == NULL) {
                cout << "Data tidak ditemukan!" << endl;
                return;
            }
            
            if (prev == NULL) {
                head = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            
            delete ptr;
            cout << "Data berhasil dihapus!" << endl;
        }
};

int main() {
    LinkedList list;
    
    list.insert(5);
    list.insert(10);
    list.insert(15);
    
    list.traverse();
    
    list.search(10);
    list.search(20);
    
    list.deleteNode(10);
    
    list.traverse();
    
    return 0;
}
