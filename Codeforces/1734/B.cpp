#include <bits/stdc++.h>

using namespace std;
#define int long long

int N;

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cout << 1 << ' ';
        for (int j = 2; j <= i - 1; j++) {
            cout << 0 << ' ';
        }
        if (i >= 2) cout << 1 << ' ';

        cout << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}