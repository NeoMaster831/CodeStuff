#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, M, D, P[200001], Q[200001], pos[200001];

void solve() {

    cin >> N >> M >> D;
    for (int i = 1; i <= N; i++) {
        cin >> P[i]; Q[P[i]] = i;
    }

    for (int i = 1; i <= M; i++) {
        int inp; cin >> inp;
        pos[i] = Q[inp];
        //cout << pos[i] << ' ';
    }

    int ans = 0;
    for (int i = 2; i <= M; i++) {
        if (pos[i - 1] > pos[i] || pos[i] > pos[i - 1] + D) continue;
        // 1. 최대로 늘리기.
        if (N - pos[i - 1] <= D) {
            int remain = D - N + pos[i - 1];
            ans += N - pos[i - 1] + remain;
        } else {
            int dest = pos[i - 1] + D + 1;
            ans += dest - pos[i];
            pos[i] = dest;
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