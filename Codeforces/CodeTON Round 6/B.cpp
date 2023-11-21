#include <bits/stdc++.h>

using namespace std;
#define int long long

int a[200001], b[200001];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    } for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    if (n % 2 == 1) {
        
        int msum = 0;
        for (int i = 1; i <= n; i++) {
            msum ^= a[i];
        }
        
        int l = 0;
        for (int i = 1; i <= m; i++) {
            l |= b[i];
        }
        for (int i = 1; i <= n; i++) {
            a[i] |= l;
        }

        int Msum = 0;
        for (int i = 1; i <= n; i++) {
            Msum ^= a[i];
        }

        cout << msum << ' ' << Msum << '\n';
    } else {

        int Msum = 0;
        for (int i = 1; i <= n; i++) {
            Msum ^= a[i];
        }
        
        int l = 0;
        for (int i = 1; i <= m; i++) {
            l |= b[i];
        }
        for (int i = 1; i <= n; i++) {
            a[i] |= l;
        }

        int msum = 0;
        for (int i = 1; i <= n; i++) {
            msum ^= a[i];
        }
        cout << msum << ' ' << Msum << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}