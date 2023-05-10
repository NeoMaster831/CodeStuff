#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    string s; cin >> s;
    char g = s[0];

    bool allg = true;
    for (int i = 1; i < s.size(); i++) {
        if (g != s[i]) { allg = false; break; }
    }

    if (allg) cout << -1 << '\n';
    else cout << s.size() - 1 << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}