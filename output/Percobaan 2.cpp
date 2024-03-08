#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Queue
struct Node {
    string item;
    int quantity;
    Node* next;
};

// Kelas Queue menggunakan LinkedList
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Menambahkan item ke queue
    void enqueue(string item, int quantity) {
        Node* newNode = new Node;
        newNode->item = item;
        newNode->quantity = quantity;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else { 
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Item \"" << item << "\" dengan jumlah " << quantity << " berhasil ditambahkan ke dalam gudang." << endl;
    }

    // Menghapus item dari queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Gudang kosong." << endl;
        } else {
            Node* temp = front;
            front = front->next;
            cout << "Item \"" << temp->item << "\" dengan jumlah " << temp->quantity << " berhasil dihapus dari gudang." << endl;
            delete temp;
        }
    }

    // Menampilkan item terdepan pada queue
    void peek() {
        if (isEmpty()) {
            cout << "Gudang kosong." << endl;
        } else {
            cout << "Item terdepan: \"" << front->item << "\" dengan jumlah " << front->quantity << endl;
        }
    }

    // Memeriksa apakah queue kosong
    bool isEmpty() {
        return front == nullptr;
    }
};

// Kelas Stack menggunakan Array
class Stack {
private:
    static const int MAX_SIZE = 100;
    string items[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Menambahkan item ke stack
    void push(string item) {
        if (top == MAX_SIZE - 1) {
            cout << "Tempat sampah penuh." << endl;
        } else {
            items[++top] = item;
            cout << "Item \"" << item << "\" berhasil ditambahkan ke dalam tempat sampah." << endl;
        }
    }

    // Menghapus item dari stack
    void pop() {
        if (isEmpty()) {
            cout << "Tempat sampah kosong." << endl;
        } else {
            string item = items[top--];
            cout << "Item \"" << item << "\" berhasil dihapus dari tempat sampah." << endl;
        }
    }

    // Menampilkan item teratas pada stack
    void peek() {
        if (isEmpty()) {
            cout << "Tempat sampah kosong." << endl;
        } else {
            cout << "Item teratas di tempat sampah: \"" << items[top] << "\"" << endl;
        }
    }

    // Memeriksa apakah stack kosong
    bool isEmpty() {
        return top == -1;
    }
};

// Kelas Array untuk Gudang
class Warehouse {
private:
    static const int MAX_SIZE = 100;
    string items[MAX_SIZE];
    int quantities[MAX_SIZE];
    int count;

public:
    Warehouse() {
        count = 0;
    }

    // Menambahkan item ke gudang
    void addItem(string item, int quantity){
        if (count == MAX_SIZE) {
            cout << "Gudang penuh." << endl;
        } else {
            items[count] = item;
            quantities[count] = quantity;
            count++;
            cout << "Item \"" << item << "\" dengan jumlah " << quantity << " berhasil ditambahkan ke dalam gudang." << endl;
        }
    }

    // Menghapus item dari gudang
    void removeItem(string item) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (items[i] == item) {
                found = true;
                for (int j = i; j < count - 1; j++) {
                    items[j] = items[j + 1];
                    quantities[j] = quantities[j + 1];
                }
                count--;
                break;
            }
        }

        if (found) {
            cout << "Item \"" << item << "\" berhasil dihapus dari gudang." << endl;
        } else {
            cout << "Item \"" << item << "\" tidak ditemukan di gudang." << endl;
        }
    }

    // Menampilkan item terdepan pada gudang
    void showFront() {
        if (count == 0) {
            cout << "Gudang kosong." << endl;
        } else {
            cout << "Item terdepan: \"" << items[0] << "\" dengan jumlah " << quantities[0] << endl;
        }
    }
};

int main() {
    Queue warehouseQueue;
    Stack trashStack;
    Warehouse warehouse;

    cout << "Program Pergudangan" << endl;
    cout << "-------------------" << endl;

    int choice;
    string item;
    int quantity;

    do {
        cout << "\nPilihan Menu:" << endl;
        cout << "1. Tambah Item ke Gudang" << endl;
        cout << "2. Hapus Item dari Gudang" << endl;
        cout << "3. Tampilkan Item Terdepan di Gudang" << endl;
        cout << "4. Buang Item dari Gudang ke Tempat Sampah" << endl;
        cout << "5. Tampilkan Item Teratas di Tempat Sampah" << endl;
        cout << "6. Keluar" << endl;
        cout << "\nPilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nama item: ";
                cin >> item;
                cout << "Masukkan jumlah item: ";
                cin >> quantity;
                warehouse.addItem(item, quantity);
                break;
            case 2:
                cout << "Masukkan nama item yang akan dihapus: ";
                cin >> item;
                warehouse.removeItem(item);
                break;
            case 3:
                warehouse.showFront();
                break;
            case 4:
                cout << "Masukkan nama item yang akan dibuang: ";
                cin >> item;
                trashStack.push(item);
                break;
            case 5:
                trashStack.peek();
                break;
            case 6:
                cout << "Terima kasih. Sampai jumpa!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}

