#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key) : val(key), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    } else {
        if (root->val < key) {
            root->right = insert(root->right, key);
        } else {
            root->left = insert(root->left, key);
        }
    }
    return root;
}

void inOrderTraversal(TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->val << " ";
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(TreeNode* root) {
    if (root) {
        cout << root->val << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(TreeNode* root) {
    if (root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->val << " ";
    }
}

int main() {
    // Membuat BST
    int keys[] = {7, 5, 12, 3, 6, 1, 4, 9};
    TreeNode* root = nullptr;

    for (int key : keys) {
        root = insert(root, key);
    }

    // InOrder Traversal
    cout << "InOrder Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // PreOrder Traversal
    cout << "PreOrder Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    // PostOrder Traversal
    cout << "PostOrder Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
