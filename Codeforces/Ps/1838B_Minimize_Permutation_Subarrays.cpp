#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;

    int oneloc, twoloc;
    pair<int, int> maxi;
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp;
        if (inp == 1) oneloc = i;
        else if (inp == 2) twoloc = i;
        maxi = max(maxi, {inp, i});
    }

    int diff1 = abs(maxi.second - oneloc), diff2 = abs(maxi.second - twoloc);

    if (max(diff2, diff1) <= abs(oneloc - twoloc)) { cout << "1 1\n"; return; }
    if (diff1 > diff2) {
       cout << maxi.second << ' ' << twoloc << '\n';
    } else cout << maxi.second << ' ' << oneloc << '\n';

}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}