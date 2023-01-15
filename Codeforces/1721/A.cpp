#include <bits/stdc++.h>

using namespace std;
#define int long long

bool x[26];

void solve() {

    int distinct = 0;
    for (int i = 0; i < 2; i++) {
        string s; cin >> s;
        for (int j = 0; j < 2; j++) {
            cout << "AAAA: " << x[s[j] - 97] << '\n';
            if (x[s[j] - 97]) continue; x[s[j] - 97] = true;
            cout << "BBBB" << '\n';
            distinct++;
        }
    }

    cout << distinct - 1 << '\n';
}

signed main() {
    int T; cin >> T;
    while (T--) solve();
}