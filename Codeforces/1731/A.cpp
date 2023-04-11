#include <bits/stdc++.h>

using namespace std;
#define int long long

int N;

void solve() {

    cin >> N;

    int ans = 1;
    for (int i = 1; i <= N; i++) {
        int inp; cin >> inp;
        ans *= inp;
    }
    ans += N - 1;
    cout << ans * 2022 << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}