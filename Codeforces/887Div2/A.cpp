#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, a[501];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int mini = 9876543212345678;
    for (int i = 1; i <= n - 1; i++) {
        mini = min(mini, a[i + 1] - a[i]);
    }
    if (mini < 0) cout << 0 << '\n';
    else cout << (mini / 2) + 1 << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}