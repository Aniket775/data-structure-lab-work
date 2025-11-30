#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertNode(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
            tail->next = head;
            cout << "Added " << value << " as the first node." << endl;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
        cout << "Added " << value << " to the list." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Circular Linked List values: ";
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        
        cout << head->data << endl;
    }
};

int main() {
    CircularLinkedList cll;

    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        cll.insertNode(value);
    }

    cll.display();

    return 0;
}
