#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[101];

void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int divider = A[1] * 2 - 1;
    int ans = 0;
    for (int i = 2; i <= N; i++) {
        int preans;
        if (A[i] % divider == 0) preans = A[i] / divider;
        else preans = A[i] / divider + 1;
        preans--;

        ans += preans;
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}