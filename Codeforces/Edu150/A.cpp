#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    if (n <= 4) cout << "Bob" << '\n';
    else cout << "Alice" << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}