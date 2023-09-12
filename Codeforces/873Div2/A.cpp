#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << 2 * i << ' ';
    }
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}