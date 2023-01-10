#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAXN 110

int N, K, D;
int A[MAXN], dp[MAXN][MAXN][MAXN];
#define INF 98765432123456

int solve(int idx, int val, int used) {

    int& cache = dp[idx][val][used];
    if (used == K) {
        if (val % D != 0) return -INF;
        else return cache = 0;
    }
    if (idx > N) return -INF;

    if (cache != -1) return cache;

    int use = solve(idx + 1, ((val + A[idx]) % D), used + 1) + A[idx];
    int dont = solve(idx + 1, val, used);
    cache = max(use, dont);

    return cache;
}

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K >> D;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    memset(dp, -1, sizeof(dp));

    int ans = solve(1, 0, 0);
    if (ans < 0) cout << -1 << '\n';
    else cout << ans << '\n';
}