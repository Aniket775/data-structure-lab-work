
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
    for (char c: originalString) {
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
    for (char currentChar: expr) {
        if (currentChar == '(' || currentChar == '{' || currentChar == '[') {
            s.push(currentChar);
        } else if (currentChar == ')' || currentChar == '}' || currentChar == ']') {
            if (s.empty()) {
                return false;
            }
            if (currentChar == ')' && s.top() == '(') {
                s.pop();
            } else if (currentChar == '}' && s.top() == '{') {
                s.pop();
            } else if (currentChar == ']' && s.top() == '[') {
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
    cout << "Enter an expression to check for balanced parentheses: ";
    getline(cin, expression);
    if (areParenthesesBalanced(expression)) {
        cout << "The expression has BALANCED parentheses. ?" << endl;
    } else {
        cout << "The expression has UNBALANCED parentheses. ?" << endl;
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
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
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
    cout << "Enter an Infix expression: ";
    getline(cin, infix_expression);
    string postfix_expression = infixToPostfix(infix_expression);
    cout << "Postfix expression: " << postfix_expression << endl;
    return 0;
}


//5

#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

int evaluatePostfix(string s) {
    stack<int> st;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();
            switch (c) {
                case '+': st.push(op1 + op2); break;
                case '-': st.push(op1 - op2); break;
                case '*': st.push(op1 * op2); break;
                case '/': st.push(op1 / op2); break;
                case '^': st.push(pow(op1, op2)); break;
            }
        }
    }
    return st.top();
}

int main() {
    string postfix_expression;
    cout << "Enter a Postfix expression (e.g., 23*5+): ";
    getline(cin, postfix_expression);
    int result = evaluatePostfix(postfix_expression);
    cout << "Result: " << result << endl;
    return 0;
}



