#include <iostream>
using namespace std;

//  DOUBLY LINKED LIST 
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            cout << "Inserted " << value << " as the first node." << endl;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        cout << "Inserted " << value << " at the beginning." << endl;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            cout << "Inserted " << value << " as the first node." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted " << value << " at the end." << endl;
    }

    void insertAfterValue(int key, int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != key)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Node with value " << key << " not found." << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr)
            temp->next->prev = newNode;

        temp->next = newNode;

        cout << "Inserted " << value << " after node " << key << "." << endl;
    }

    void deleteNode(int key) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;

        if (temp->data == key) {
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            delete temp;
            cout << "Deleted node " << key << "." << endl;
            return;
        }

        while (temp != nullptr && temp->data != key)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Node not found." << endl;
            return;
        }

        if (temp->next != nullptr)
            temp->next->prev = temp->prev;

        if (temp->prev != nullptr)
            temp->prev->next = temp->next;

        delete temp;
        cout << "Deleted node " << key << "." << endl;
    }

    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << "." << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        cout << "Doubly Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// CIRCULAR LINKED LIST 
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
            cout << "Inserted " << value << " as the first node." << endl;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
        cout << "Inserted " << value << " at the end." << endl;
    }

    void deleteNode(int key) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;

        do {
            if (curr->data == key) {
                if (curr == head) {
                    if (head == tail) {
                        head = tail = nullptr;
                    } else {
                        head = head->next;
                        tail->next = head;
                    }
                } else if (curr == tail) {
                    tail = prev;
                    tail->next = head;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                cout << "Deleted node " << key << "." << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        cout << "Node not found." << endl;
    }

    void search(int key) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << "." << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);

        cout << "Node not found." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, value, key;
    cout << "--- MENU: DOUBLY & CIRCULAR LINKED LIST ---" << endl;
    cout << "1. Insert (Doubly)" << endl;
    cout << "2. Delete (Doubly)" << endl;
    cout << "3. Search (Doubly)" << endl;
    cout << "4. Display (Doubly)" << endl;
    cout << "5. Insert (Circular)" << endl;
    cout << "6. Delete (Circular)" << endl;
    cout << "7. Search (Circular)" << endl;
    cout << "8. Display (Circular)" << endl;
    cout << "9. Exit" << endl;

    do {
        cout << endl << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                dll.insertAtEnd(value);
                break;
            case 2:
                cout << "Enter node value to delete: ";
                cin >> key;
                dll.deleteNode(key);
                break;
            case 3:
                cout << "Enter node value to search: ";
                cin >> key;
                dll.search(key);
                break;
            case 4:
                dll.display();
                break;
            case 5:
                cout << "Enter value: ";
                cin >> value;
                cll.insertNode(value);
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> key;
                cll.deleteNode(key);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> key;
                cll.search(key);
                break;
            case 8:
                cll.display();
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 9);

    return 0;
}
