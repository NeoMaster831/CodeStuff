#include <bits/stdc++.h>

using namespace std;
#define INF 987654321

int N, X, ans[200001];

void solve() {
    
    cin >> N >> X;

    if (N % X != 0) {
        cout << -1 << '\n';
        return;
    }

    int toswap = INF;
    for (int i = 2; i <= N - 1; i++) {
        if (N % i == 0 && i % X == 0 && i != X) {
            toswap = min(toswap, i);
        }
    }

    ans[1] = X; ans[N] = 1;
    for (int i = 2; i <= N - 1; i++) {
        ans[i] = i;
    }
    if (X != N) ans[X] = N;

    if (toswap != INF) {
        ans[toswap] = N;
        ans[X] = toswap;
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}