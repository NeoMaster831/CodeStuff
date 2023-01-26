#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pp pair<int, int>

int N;
string S;
int chk[100001];

void dfs(int X, int K) {
    
    if (S[X - 1] == '1') return;
    if (X > N) return;
    if (chk[X] != 0 && chk[X] <= K) return;

    chk[X] = K;

    if (S[X + K - 1] != '1') dfs(X + K, K);
    dfs(X * 2, X);
}

void solve() {

    cin >> N >> S;

    for (int i = 1; i <= N; i++) chk[i] = 0;
    for (int i = 1; i <= N; i++) {
        dfs(i, i);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        //cout << chk[i] << ' ';
        ans += chk[i];
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}