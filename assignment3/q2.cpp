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
