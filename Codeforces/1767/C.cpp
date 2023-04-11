#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[101][101], dp[101][101][2][2];

void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N - i + 1; j++) {
            cin >> A[i][j];
        }
    }
    
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}