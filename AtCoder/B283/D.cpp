#include <bits/stdc++.h>

using namespace std;

string S; stack<char> st;
bool ck[26];

int main() {

    cin >> S;

    for (int i = 0; i < S.size(); i++) {

        char c = S[i];
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (st.top() != '(') {
                ck[st.top() - 97] = false;
                st.pop();
            }
            st.pop();
        } else {
            if (ck[c - 97] == true) { cout << "No" << '\n'; return 0; }
            else { ck[c - 97] = true; st.push(c); }
        }

    }

    cout << "Yes" << '\n';
}