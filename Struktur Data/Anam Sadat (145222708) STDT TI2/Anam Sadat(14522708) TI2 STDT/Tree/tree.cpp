#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

// Struktur node untuk tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Fungsi untuk menambahkan node ke dalam tree secara rekursif
Node* insertNode(int data, int level, int maxLevel) {
    if (level > maxLevel || data < 0) {
        return nullptr;
    }

    Node* newNode = new Node(data);
    newNode->left = insertNode(2 * data, level + 1, maxLevel);
    newNode->right = insertNode(2 * data + 1, level + 1, maxLevel);

    return newNode;
}

// Fungsi untuk mencetak parents setiap node
void printParents(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << "->";

    if (root->left != nullptr) {
        cout << root->left->data << " ";
    }

    if (root->right != nullptr) {
        cout << root->right->data << " ";
    }

    cout << endl;

    printParents(root->left);
    printParents(root->right);
}

// Fungsi untuk mencetak children setiap node
void printChildren(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << "->";

    if (root->left != nullptr) {
        cout << root->left->data << " ";
    }

    if (root->right != nullptr) {
        cout << root->right->data << " ";
    }

    cout << endl;

    printChildren(root->left);
    printChildren(root->right);
}

// Fungsi untuk mencetak leaf nodes dari tree
void printLeafNodes(Node* root) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

// Fungsi untuk mencetak degrees setiap node
void printDegrees(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << ": ";

    int degree = 0;

    if (root->left != nullptr) {
        degree++;
    }

    if (root->right != nullptr) {
        degree++;
    }

    cout << degree << endl;

    printDegrees(root->left);
    printDegrees(root->right);
}

int main() {
    int maxLevel;
    cout << "Masukkan tingkat maksimum untuk tree: ";
    cin >> maxLevel;

    // Membuat tree dengan tingkat maksimum yang dimasukkan
    Node* root = insertNode(1, 1, maxLevel);

    cout << "The parents of each node are:" << endl;
    printParents(root);

    cout << "The children of each node are:" << endl;
    printChildren(root);

    cout << "The leaf nodes of the tree are:" << endl;
    printLeafNodes(root);
    cout << endl;

    cout << "The degrees of each node are:" << endl;
    printDegrees(root);

    return 0;
}
