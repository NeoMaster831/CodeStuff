#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int N, A[100001];

    cin >> N;
    
    int sum = 0, _1s = 0, _2s = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sum += A[i];
        if (A[i] == 1) _1s++;
        else if (A[i] == 2) _2s++;
    }

    if (N == 1) {
        cout << "no" << '\n'; return;
    }

    if (_1s < 1 || _1s <= _2s) {
        cout << "yes" << '\n'; return;
    }
    sum -= _2s;
    cout << N - _2s << ' ';
    cout << ((N - _2s) * 2 < sum ? "NO" : "YES") << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}