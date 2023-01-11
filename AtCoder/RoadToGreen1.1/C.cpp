#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, X;
string s;

signed main() {

    cin >> N >> X;
    cin >> s;

    stack<char> q;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'U') {
            if (q.empty()) {
                q.push('U');
                continue;
            }
            if (q.top() == 'L' || q.top() == 'R') {
                q.pop();
            }
            else q.push('U');
        }
        else q.push(s[i]);
    }

    stack<char> rev;
    while (!q.empty()) {
        char operation = q.top(); q.pop();
        rev.push(operation);
    }

    while (!rev.empty()) {
        char operation = rev.top(); rev.pop();
        if (operation == 'U') X /= 2;
        else if (operation == 'L') X = 2 * X;
        else X = 2 * X + 1;
    }

    cout << X << '\n';
}