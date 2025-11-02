
//1
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
            cout << "Stack is full, you can’t push any more elements." << endl;
            return;
        }
        st[++top] = val;
        cout << "Added " << val << " to the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty, nothing to remove." << endl;
            return;
        }
        cout << "Removed " << st[top--] << " from the stack." << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty right now." << endl;
            return;
        }
        cout << "The top element is " << st[top] << "." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty, nothing to show." << endl;
            return;
        }
        cout << "Stack (from top to bottom): ";
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
        cout << endl << "--- STACK MENU ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value you want to push: ";
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
                cout << (s.isEmpty() ? "Yes, the stack is empty." : "No, the stack is not empty.") << endl;
                break;
            case 6:
                cout << (s.isFull() ? "Yes, the stack is full." : "No, the stack is not full.") << endl;
                break;
            case 7:
                cout << "Okay, exiting now." << endl;
                break;
            default:
                cout << "That’s not a valid choice, try again." << endl;
        }
    } while (choice != 7);

    return 0;
}


//2

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string originalString;
    string reversedString = "";

    cout << "Enter a string to reverse: ";
    getline(cin, originalString);

    stack<char> charStack;

    for (char c : originalString) {
        charStack.push(c);
    }

    while (!charStack.empty()) {
        reversedString += charStack.top();
        charStack.pop();
    }

    cout << "Reversed string: " << reversedString << endl;

    return 0;
}


//3

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool areParenthesesBalanced(string expr) {
    stack<char> s;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) {
                return false;
            }
            if ((c == ')' && s.top() == '(') ||
                (c == '}' && s.top() == '{') ||
                (c == ']' && s.top() == '[')) {
                s.pop();
            } else {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    string expression;
    cout << "Enter an expression to check: ";
    getline(cin, expression);

    if (areParenthesesBalanced(expression)) {
        cout << "All parentheses are balanced." << endl;
    } else {
        cout << "Parentheses are not balanced." << endl;
    }

    return 0;
}


//4

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (isalnum(c)) {
            ans += c;
        } else if (c == '(') {
            st.push('(');
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        } else {
            while (!st.empty() && precedence(c) <= precedence(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main() {
    string infix_expression;
    cout << "Enter an infix expression: ";
    getline(cin, infix_expression);

    string postfix_expression = infixToPostfix(infix_expression);
    cout << "Postfix form: " << postfix_expression << endl;

    return 0;
}


//5

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


