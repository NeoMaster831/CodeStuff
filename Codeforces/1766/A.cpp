#include <bits/stdc++.h>

using namespace std;
#define int long long

string N;

void solve() {
    
    cin >> N;
    
    int ans = 0;
    ans += N[0] - 48;
    for (int i = 1; i < N.size(); i++) ans += 9;

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}