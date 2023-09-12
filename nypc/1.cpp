#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    string s;
    cin >> n;
    cin >> s;

    stack<char> st;
    int ans = 0;
    for (int i =0; i < s.size(); i++) {
        if (!st.empty() && st.top() == '(' && s[i] == ')') {
            st.pop();
            ans++;
        }
        else st.push(s[i]);
    }

    cout << ans + st.size() << '\n';
}