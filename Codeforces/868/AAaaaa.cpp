#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, k;

void solve() {
    cin >> n >> k;
    for (int i = 0; i <= n; i++) { // number of 1s

        vector<int> pre;
        for (int j = 1; j <= i; j++) {
            pre.push_back(-1);
        }
        for (int j = i + 1; j <= n; j++) {
            pre.push_back(1);
        }

        int ans = 0;
        for (int j = 0; j < pre.size(); j++) {
            for (int k = j + 1; k < pre.size(); k++) {
                ans += pre[j] * pre[k] == 1;
            }
        }

        if (ans == k) {
            cout << "yes" << '\n';
            for (int j = 0; j < pre.size(); j++) {
                cout << pre[j] << ' ';
            }
            cout << '\n';
            return;
        }
    }
    cout << "no" << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}