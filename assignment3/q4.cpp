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
