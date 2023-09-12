#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, a[200001];

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int mini = a[1];
    for (int i = 2; i <= n; i++) {
        mini = mini & a[i];
    }
    if (mini != 0) { cout << 1 << '\n'; return; }

    int last = a[1];
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (last != mini) last &= a[i];
        else {
            last = a[i];
            ans++;
        }
    }
    if (last == mini) ans++;

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}