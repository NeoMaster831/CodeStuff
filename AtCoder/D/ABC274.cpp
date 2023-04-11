#include <bits/stdc++.h>

using namespace std;
#define MIDDLE 10000
#define int long long

int dp[1010][20003]; // idx, x -> y
int N, C[2];
int A[1001];

int solve(int idx, int val) {

    int yx = idx % 2;
    int& cache = dp[idx][val + MIDDLE];

    if (cache != -1) return cache;
    if (idx > N) {
        if (val == C[!yx]) return cache = 1;
        else return cache = 0;
    }

    int add = solve(idx + 2, val + A[idx]);
    int sub = (idx == 1) ? 0 : solve(idx + 2, val - A[idx]);
    cache = (add || sub);

    return cache;
}

signed main() {
    
    cin >> N >> C[0] >> C[1];
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    memset(dp, -1, sizeof(dp));

    int x = solve(1, 0), y = solve(2, 0);
    if (x && y) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}