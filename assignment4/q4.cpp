#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    string s = "aabc";
    cout << "Input String: " << s << endl;
    cout << "Output Stream: ";

    int freq[26] = {0};
    queue<char> q;

    for (int i = 0; i < s.length(); i++) {
        char currentChar = s[i];
        q.push(currentChar);
        freq[currentChar - 'a']++;

        while (!q.empty()) {
            if (freq[q.front() - 'a'] > 1) {
                q.pop();
            } else {
                break;
            }
        }

        if (q.empty()) {
            cout << -1 << " ";
        } else {
            cout << q.front() << " ";
        }
    }

    cout << endl;
    return 0;
}
