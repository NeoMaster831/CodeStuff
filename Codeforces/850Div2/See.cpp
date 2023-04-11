#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[200001];

void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + N + 1);

    int to = 0, ans = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] == to) continue;
        else {
            to++;
            ans += A[i] - to;
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