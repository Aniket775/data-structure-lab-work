#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void findMiddle() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle element is: " << slow->data << endl;
    }
};

int main() {
    LinkedList list;
    for (int i = 1; i <= 5; i++)
        list.insertAtEnd(i);

    list.findMiddle();
    return 0;
}
