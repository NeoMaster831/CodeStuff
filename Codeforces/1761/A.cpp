#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A, B;

void solve() {

    cin >> N >> A >> B;
    if (N + A + B == 3) { cout << "Yes" << '\n'; return; }

    if (N - A - B >= 2) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}