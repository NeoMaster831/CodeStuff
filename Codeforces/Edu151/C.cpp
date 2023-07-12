#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    string s, l, r; cin >> s;
    int m; cin >> m;
    cin >> l >> r;

    set<int> se;
    int ptr = 0;
    for (int i = 0; i < s.size(); i++) {
        //cout << ptr << '\n';
        int val = s[i] - 48;
        if (val <= r[ptr] - 48 && val >= l[ptr] - 48) se.insert(val);
        if (se.size() == r[ptr] - l[ptr] + 1) { // 다 찼으면
            se.clear();
            ptr++;
        }
        if (ptr >= m) break;
    }
    if (ptr < m) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}