#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    Node* insert(Node* node, int value) {
        if (node == NULL) {
            node = new Node(value);
        }
        else if (value <= node->data) {
            node->left = insert(node->left, value);
        }
        else {
            node->right = insert(node->right, value);
        }

        return node;
    }

    void preorder() {
        preorder(root);
    }

    void preorder(Node* node) {
        if (node == NULL) return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder() {
        inorder(root);
    }

    void inorder(Node* node) {
        if (node == NULL) return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder() {
        postorder(root);
    }

    void postorder(Node* node) {
        if (node == NULL) return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void printTree(int node) {
        if (node == 1) {
            cout << "pre-order : ";
            preorder(root);
            cout << endl;
        }
        else if (node == 2) {
            cout << "in-order : ";
            inorder(root);
            cout << endl;
        }
        else if (node == 3) {
            cout << "post-order : ";
            postorder(root);
            cout << endl;
        }
        else {
            cout << "Pilihan tidak valid" << endl;
        }
    }
};

int main() {
    Tree tree;
    int n, data;

    cout << "Masukkan jumlah simpul: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan simpul" << i + 1 << ": ";
        cin >> data;
        tree.insert(data);
    }

    cout <<"\n==============================\n";
    tree.printTree(1);
    cout<<endl;
    tree.printTree(2);
    cout<<endl;
    tree.printTree(3);
    cout<<endl;

    return 0;
}
