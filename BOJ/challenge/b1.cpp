#include <bits/stdc++.h>

using namespace std;

signed main() {

    int n; cin >> n;
    string s; cin >> s;
    for (int i = 2; i <= n; i++) {
        string t; cin >> t;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) s[i] = '?';
        }
    }
    cout << s << '\n';
}