#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MOD 1000000007

int N;

int sum1toX(int X) {
    return X * (X + 1) / 2;
}

void solve() {

    cin >> N;

    int f = sum1toX(N - 1) * 2;
    for (int i = N; i >= 1; i--) {
        f = (f % MOD) * (i % MOD) % MOD;
    }

    cout << f << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}