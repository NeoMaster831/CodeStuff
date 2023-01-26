#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[101];

void solve() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    for (int i = 1; i <= N - 1; i++) {
        if (A[i] % 2 == A[i + 1] % 2) { // Same parity
            ans++;
        }
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}