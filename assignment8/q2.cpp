//(a) 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    while (root != NULL && root->data != key) {
        root = (key < root->data) ? root->left : root->right;
    }
    return root;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int key = 10;
    cout << (searchRecursive(root, key) ? "Found" : "Not Found") << endl;
    cout << (searchIterative(root, key) ? "Found" : "Not Found") << endl;
}

//(b) and (c) 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    cout << "Min: " << findMin(root)->data << endl;
    cout << "Max: " << findMax(root)->data << endl;
}

//(d) & (e) 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* succ = NULL;
    while (root) {
        if (key < root->data) {
            succ = root;
            root = root->left;
        } else if (key > root->data)
            root = root->right;
        else {
            if (root->right) succ = findMin(root->right);
            break;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* pred = NULL;
    while (root) {
        if (key > root->data) {
            pred = root;
            root = root->right;
        } else if (key < root->data)
            root = root->left;
        else {
            if (root->left) pred = findMax(root->left);
            break;
        }
    }
    return pred;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    Node* succ = inorderSuccessor(root, 10);
    Node* pred = inorderPredecessor(root, 10);
    cout << "Successor of 10: " << (succ ? succ->data : -1) << endl;
    cout << "Predecessor of 10: " << (pred ? pred->data : -1) << endl;
}
