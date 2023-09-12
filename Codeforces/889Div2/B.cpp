#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int N; cin >> N;
    int i;
    for (i = 1; N % i == 0; i++);
    i--;
    cout << i << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}