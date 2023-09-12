#include <bits/stdc++.h>

using namespace std;
#define int long long

int N;

void solve() {

    cin >> N;
    int k = 0;
    for (int i = 1; i <= N; i++) {
        int inp; cin >> inp; if (inp == i) k++;
    }

    cout << k / 2 + (k % 2) << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}