//1

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

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at the beginning." << endl;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted " << val << " at the end." << endl;
    }

    void insertAfterValue(int key, int val) {
        Node* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << "Node with value " << key << " not found." << endl;
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << val << " after node " << key << "." << endl;
    }

    void insertBeforeValue(int key, int val) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Node with value " << key << " not found." << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << val << " before node " << key << "." << endl;
    }

    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted node from beginning." << endl;
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Deleted the only node in the list." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
        cout << "Deleted node from end." << endl;
    }

    void deleteSpecificNode(int key) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted node with value " << key << "." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Node with value " << key << " not found." << endl;
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
        cout << "Deleted node with value " << key << "." << endl;
    }

    void searchNode(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << "." << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found in the list." << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Current Linked List: ";
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, val, key;

    do {
        cout << endl << "---- MENU ----" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert Before a Value" << endl;
        cout << "4. Insert After a Value" << endl;
        cout << "5. Delete from Beginning" << endl;
        cout << "6. Delete from End" << endl;
        cout << "7. Delete a Specific Node" << endl;
        cout << "8. Search a Node" << endl;
        cout << "9. Display List" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter value and key (value before which to insert): ";
            cin >> val >> key;
            list.insertBeforeValue(key, val);
            break;
        case 4:
            cout << "Enter value and key (value after which to insert): ";
            cin >> val >> key;
            list.insertAfterValue(key, val);
            break;
        case 5:
            list.deleteFromBeginning();
            break;
        case 6:
            list.deleteFromEnd();
            break;
        case 7:
            cout << "Enter value to delete: ";
            cin >> key;
            list.deleteSpecificNode(key);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> key;
            list.searchNode(key);
            break;
        case 9:
            list.display();
            break;
        case 10:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 10);

    return 0;
}

//2
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

    void countAndDelete(int key) {
        int count = 0;
        while (head != NULL && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }

        Node* curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (curr->next->data == key) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                count++;
            } else {
                curr = curr->next;
            }
        }

        cout << "Count: " << count << endl;
        cout << "Updated List: ";
        display();
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(1);

    int key = 1;
    cout << "Original List: ";
    list.display();
    cout << "Deleting all occurrences of " << key << "..." << endl;
    list.countAndDelete(key);
    return 0;
}


//3

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


//4

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

    void reverseList() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        cout << "List has been reversed successfully." << endl;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << "->";
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }
};

int main() {
    LinkedList list;
    for (int i = 1; i <= 4; i++)
        list.insertAtEnd(i);

    cout << "Original List: ";
    list.display();

    list.reverseList();

    cout << "Reversed List: ";
    list.display();

    return 0;
}







