#include <bits/stdc++.h>

using namespace std;

int N;
string S;

int main() {

    cin >> N >> S;

    stack<char> st;
    for (int i = 0; i < S.size(); i++) {
        if (st.empty()) { st.push(S[i]); continue; }
        if (S[i] == '(') {
            st.push('(');
        } else {
            if (st.top() == '(') {
                st.pop();
            }
            else st.push(')');
        }
    }

    stack<char> rev;
    while (!st.empty()) {
        char op = st.top(); st.pop(); rev.push(op);
    }

    int l = 0, r = 0;
    while (!rev.empty()) {
        char op = rev.top(); rev.pop();
        if (op == ')') l++;
        else r++;
    }

    for (int i = 1; i <= l; i++) cout << '(';
    cout << S;
    for (int i = 1; i <= r; i++) cout << ')';
    cout << '\n';
}