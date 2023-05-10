#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, M, B[200001];

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N * M; i++) cin >> B[i];


    // 2 mins, 1 max or 1 min, 2 maxs
    sort(B + 1, B + N * M + 1);
    int maxi = B[N * M], mini = B[1];

    int _2m1M = (maxi - mini) * (max(N, M) - 1);
    _2m1M += (maxi - mini) * (N - 1) * (M - 1);
    int _1m2M = _2m1M;

    _2m1M += (maxi - B[2]) * (min(N, M) - 1);
    _1m2M += (B[N * M - 1] - mini) * (min(N, M) - 1);

    cout << max(_2m1M, _1m2M) << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}