//using 2 queues

#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
private:
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        cout << "Pushed " << x << " onto the stack." << endl;
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty, nothing to pop." << endl;
            return;
        }
        cout << "Popped " << q1.front() << " from the stack." << endl;
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty right now." << endl;
            return -1;
        }
        return q1.front();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void display() {
        if (q1.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";
        queue<int> temp = q1;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingTwoQueues s;
    int choice, value;

    do {
        cout << endl << "--- STACK USING TWO QUEUES ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                value = s.top();
                if (value != -1)
                    cout << "Top element is " << value << "." << endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting now." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 5);

    return 0;
}


//using 1 queue
#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
private:
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << "Pushed " << x << " onto the stack." << endl;
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty, nothing to pop." << endl;
            return;
        }
        cout << "Popped " << q.front() << " from the stack." << endl;
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty right now." << endl;
            return -1;
        }
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingOneQueue s;
    int choice, value;

    do {
        cout << endl << "--- STACK USING ONE QUEUE ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                value = s.top();
                if (value != -1)
                    cout << "Top element is " << value << "." << endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting now." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}


