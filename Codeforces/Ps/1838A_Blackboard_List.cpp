#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    int maxi = -98765434676543;
    int mini = 987543456765432;
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp;
        mini = min(mini, inp);
        maxi = max(maxi, inp);
    }
    if (mini < 0) cout << mini << '\n';
    else cout << maxi << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}