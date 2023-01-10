#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MIDDLE 90000
#define MOD 998244353

int dp[301][180001];
int N, A[301];

int solve(int idx, int val) {
    
    //cout << "Index: " << idx << ", val: " << val << '\n';

    int &cache = dp[idx][val + MIDDLE];
    if (cache) return cache;
    if (idx == N) {
        return cache = 1;
    }

    int sub = solve(idx + 1, A[idx + 1] - val);
    int add = solve(idx + 1, A[idx + 1] + val);
    if (val == 0) cache = add;
    else cache = add + sub;
    
    cache %= MOD;

    return cache;
}

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    cout << solve(2, A[2]) << '\n';
}