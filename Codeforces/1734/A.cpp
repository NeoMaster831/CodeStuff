#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[301];

void solve() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + N + 1);
    
    int ans = 9999999999111;
    for (int i = 2; i <= N - 1; i++) {
        ans = min(ans, A[i] - A[i - 1] + A[i + 1] - A[i]);
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}