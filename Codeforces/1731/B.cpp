#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007
#define int long long

void solve() {
    int N; cin >> N;
    cout << ((((((N * (N + 1)) % MOD) * (4 * N - 1)) % MOD) * 2022 / 6) % MOD) << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}