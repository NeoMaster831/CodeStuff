#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n, a[100001];
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (a[n] == 1) {
        cout << "no" << '\n';
        return;
    }

    cout << "yes" << '\n';
    int onecnt = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] == 1) {
            onecnt++;
            if (a[i - 1] == 0) {
                cout << onecnt << ' ';
                continue;
            }
        } else {
            onecnt = 0;
        }
        cout << 0 << ' ';
    }
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}