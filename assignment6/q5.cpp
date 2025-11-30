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

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
            cout << "Added " << value << " as the first node." << endl;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        cout << "Added " << value << " to the end." << endl;
    }

    void makeCircular() {
        if (head == nullptr) return;
        tail->next = head; 
        cout << "Linked List is now circular." << endl;
    }

    bool isCircular() {
        if (head == nullptr) return false;

        Node* temp = head->next;
        while (temp != nullptr && temp != head)
            temp = temp->next;

        return (temp == head);
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Linked List elements: ";
        Node* temp = head;
        int count = 0;

        while (temp != nullptr && count < 20) { // to overcome infinite loop problem
            cout << temp->data << " ";
            temp = temp->next;
            count++;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        list.insertAtEnd(val);
    }

    cout << endl;
    list.display();

    char choice;
    cout << "Do you want to make it circular (y/n)? ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
        list.makeCircular();

    if (list.isCircular())
        cout << "Yes, the Linked List is Circular." << endl;
    else
        cout << "No, the Linked List is not Circular." << endl;

    return 0;
}

