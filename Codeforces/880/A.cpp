#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, cnt[101];

void solve() {
    cin >> n;
    for (int i = 0; i <= 100; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp;
        cnt[inp]++;
    }
    int prev = 12345678;
    for (int i = 0; i <= 100; i++) {
        if (prev < cnt[i]) {
            cout << "no" << '\n';
            return;
        }
        prev = cnt[i];
    }
    cout << "yes" << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}