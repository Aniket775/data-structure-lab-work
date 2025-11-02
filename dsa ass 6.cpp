//1

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

//2

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

//3

//(i)

#include <iostream>
using namespace std;

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
    Node* tail;

public:
    DoublyLinkedList() {
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
        newNode->prev = tail;
        tail = newNode;
        cout << "Added " << value << " to the end." << endl;
    }

    int findSize() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Doubly Linked List elements: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        dll.insertAtEnd(value);
    }

    dll.display();
    cout << "Size of the Doubly Linked List is: " << dll.findSize() << endl;

    return 0;
}


// (ii)

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

    int findSize() {
        if (head == nullptr)
            return 0;

        int count = 0;
        Node* temp = head;

        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Circular Linked List: ";
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
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
    cout << "Size of the Circular Linked List is: " << cll.findSize() << endl;

    return 0;
}


//4

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


//5

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


