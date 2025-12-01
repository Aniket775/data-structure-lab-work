#include <iostream>
#include <algorithm>
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

Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);
    Node* cur = root;
    while (true) {
        if (val < cur->data) {
            if (cur->left) cur = cur->left;
            else { cur->left = new Node(val); break; }
        } else if (val > cur->data) {
            if (cur->right) cur = cur->right;
            else { cur->right = new Node(val); break; }
        } else break;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left && !root->right) { delete root; return NULL; }
        if (!root->left) { Node* t = root->right; delete root; return t; }
        if (!root->right) { Node* t = root->left; delete root; return t; }
        Node* succ = findMin(root->right);
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    Node* root = NULL;
    int vals[] = {14,7,19,5,11,15,21,10,13,16,20};
    for (int x : vals) root = insert(root, x);
    root = deleteNode(root, 15);
    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;
}
