#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, P[200001];

void solve() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    int ans = N / 2;

    int l, r;
    if (N % 2 == 1) {
        for (int i = 1; i <= N; i++) {
            if (P[i] == N / 2 + 1) l = r = i;
        }
    } else {
        for (int i = 1; i <= N; i++) {
            if (P[i] == N / 2) l = i;
            else if (P[i] == N / 2 + 1) r = i;
        }
        if (l > r) { cout << ans << '\n'; return; }
        ans--;
    }

    int lo = P[l] - 1, ro = P[r] + 1;
    l--; r++;
    while (true) {
        
        while (l >= 1) {
            if (P[l] == lo) break;
            l--;
        }
        while (r <= N) {
            if (P[r] == ro) break;
            r++;
        }

        if (l < 1 || r > N) break;
        ans--; lo--; ro++;
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}