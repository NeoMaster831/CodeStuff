#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int N;
    cin >> N;

    int last = -1;

    int maxi = 0;
    for (int i = 1; i <= N; i++) {
        int inp; cin >> inp;
        if (last > inp) {
            maxi = max(maxi, last);
        }
        last = inp;
    }

    cout << maxi << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}