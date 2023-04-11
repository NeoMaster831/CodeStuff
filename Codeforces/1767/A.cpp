#include <bits/stdc++.h>

using namespace std;
#define int long long

int coord[3][2];
bool ans[2];

void solve() {

    ans[0] = ans[1] = false;
    set<int> s[2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            int x; cin >> x;
            auto f = s[j].find(x);
            if (f != s[j].end()) {
                ans[j] = true;
            }
            s[j].insert(x);
        }
    }

    /*
    for (auto iter = s[0].begin(); iter != s[0].end(); iter++) {
        cout << *iter;
    }
    */

    if (ans[0] && ans[1]) {
        cout << "NO" << '\n';
    } else cout << "YES" << '\n';
    
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}