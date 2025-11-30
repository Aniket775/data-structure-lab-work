#include <iostream>
using namespace std;

#define MAX_SIZE 10

class Stack {
private:
    int top;
    int st[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow. Cannot push " << val << "." << endl;
            return;
        }
        st[++top] = val;
        cout << "Pushed " << val << " to stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow. Cannot pop." << endl;
            return;
        }
        cout << "Popped " << st[top--] << " from stack." << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element is: " << st[top] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (Top to Bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << st[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "--- STACK MENU ---" << endl;
        cout << "1. Push   2. Pop   3. Peek   4. Display   5. IsEmpty?   6. IsFull?   7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << (s.isEmpty() ? "Result: Stack IS empty." : "Result: Stack is NOT empty.") << endl;
                break;
            case 6:
                cout << (s.isFull() ? "Result: Stack IS full." : "Result: Stack is NOT full.") << endl;
                break;
            case 7:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
        cout << endl;
    } while (choice != 7);

    return 0;
}
