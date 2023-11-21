#include <bits/stdc++.h>

using namespace std;
#define int long long

pair<int, int> a[100001];
void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp;
        a[i] = {inp, i};
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        ;
    }
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}