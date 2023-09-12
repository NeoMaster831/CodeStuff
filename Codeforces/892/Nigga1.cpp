#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n; cin >> n; int a[101];

    bool allsame = true;
    int maxi = -1;
    for (int i =1 ; i <= n; i++) {
        cin >> a[i];
        if (i >= 2 && a[i - 1] != a[i]) allsame = false;
        maxi = max(maxi, a[i]);
    }

    if (allsame) {
        cout << -1 << '\n'; return;
    }
    vector<int> b, c;
    for (int i = 1; i <= n; i++) {
        if (a[i] == maxi) c.push_back(a[i]);
        else b.push_back(a[i]);
    }

    cout << b.size() << ' ' << c.size() << '\n';
    for (int i = 0; i < b.size(); i++) cout << b[i] << ' '; cout << '\n';
    for (int i = 0; i < c.size(); i++) cout << c[i] << ' '; cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}