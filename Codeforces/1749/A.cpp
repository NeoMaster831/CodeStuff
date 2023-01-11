#include <bits/stdc++.h>

using namespace std;

int N, M;

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int di1, di2; cin >> di1 >> di2;
    }

    if (M == N) cout << "NO" << '\n';
    else cout << "YES" << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}