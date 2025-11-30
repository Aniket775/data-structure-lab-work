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
