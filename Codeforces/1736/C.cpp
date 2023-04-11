#include <bits/stdc++.h>

using namespace std;
#define int long long
#define INF 9876543212345

int N, A[200001], pmin[200001], B[200001];

void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int inp; cin >> inp; A[i] = i - inp;
    }

    for (int i = 1; i <= N; i++) B[i] = INF;
    for (int i = 1; i <= N; i++) {
        if (A[i] >= 1) {
            B[A[i]] = min(i, B[A[i]]);
        }
    }

    for (int i = N - 1; i >= 1; i--) {
        B[i] = min(B[i], B[i + 1]);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (B[i] == INF) {
            ans += N - i + 1;
            continue;
        }
        ans += B[i] - i;
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}