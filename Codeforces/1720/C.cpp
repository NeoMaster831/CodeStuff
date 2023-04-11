#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, M;
string S[501];

void solve() {
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int mingrid = 4;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 1; j++) {
            int grid = 0;
            if (S[i][j] == '1') grid++;
            if (S[i + 1][j] == '1') grid++;
            if (S[i][j + 1] == '1') grid++;
            if (S[i + 1][j + 1] == '1') grid++;
            mingrid = min(mingrid, grid);
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S[i][j] == '1') ans++;
        }
    }

    if (mingrid == 3) ans--;
    else if (mingrid == 4) ans -= 2;
    
    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}