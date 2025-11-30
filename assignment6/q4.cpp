#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(char value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    bool isPalindrome() {
        if (head == nullptr) return true;
        string forward = "", backward = "";
        Node* temp = head;
        while (temp != nullptr) {
            forward += temp->data;
            temp = temp->next;
        }
        Node* tail = head;
        while (tail->next != nullptr)
            tail = tail->next;
        while (tail != nullptr) {
            backward += tail->data;
            tail = tail->prev;
        }
        return (forward == backward);
    }

    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int n;
    char ch;

    cout << "Enter number of characters: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter character " << i + 1 << ": ";
        cin >> ch;
        dll.insertAtEnd(ch);
    }

    dll.display();

    if (dll.isPalindrome())
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;

    return 0;
}
