#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, M, P[500001], opscore[500001];
pair<int, int> A[500001];
/*
participant i has i - 1 wins in total;
*/

void solve() {
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> P[i]; A[i] = {P[i], i};
    }

    sort(A + 1, A + N + 1);

    int x = 0, left = M;
    for (int i = 1; i <= N; i++) {

        left -= A[i].first;
        if (left < 0) break;

        x++;
    }

    if (x >= N) { cout << 1 << '\n'; return; }

    int y = 1, left2 = M - P[x + 1];
    if (left2 < 0) { cout << N - x + 1 << '\n'; return; }


    for (int i = 1; i <= N; i++) {
        if (A[i].second == x + 1) {
            continue;
        }
        left2 -= A[i].first;
        if (left2 < 0) break;
        y++;
    }

    if (x == y) cout << N - x << '\n';
    else cout << N - x + 1 << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}