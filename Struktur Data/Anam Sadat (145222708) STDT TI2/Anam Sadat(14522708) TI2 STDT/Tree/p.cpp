#include <iostream>

using namespace std;

// Struktur node untuk tree biner pencarian (BST)
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Fungsi untuk menyisipkan nilai z ke dalam BST
Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Fungsi untuk mencari nilai dalam BST
bool searchNode(Node* root, int target) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == target) {
        return true;
    } else if (target < root->data) {
        return searchNode(root->left, target);
    } else {
        return searchNode(root->right, target);
    }
}

int main() {
    Node* root = nullptr;

    // Menambahkan beberapa nilai ke dalam BST
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    // Meminta pengguna untuk memasukkan nilai yang ingin dicari
    int target;
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> target;

    // Melakukan pencarian dan menampilkan hasilnya
    if (searchNode(root, target)) {
        cout << "Nilai " << target << " ditemukan dalam tree." << endl;
    } else {
        cout << "Nilai " << target << " tidak ditemukan dalam tree." << endl;
    }

    return 0;
}
