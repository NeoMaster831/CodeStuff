#include <bits/stdc++.h>

using namespace std;

int n, a[51];

void solve() {

    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 2 == 0) { cout << 0 << '\n'; return; }

    int ans = 99999999;
    for (int i = 1; i <= n; i++) {
        
        bool iseven = (a[i] % 2 == 0);
        int cnt = 0;
        while (a[i] % 2 == !iseven) {
            a[i] /= 2;
            cnt++;
        }

        ans = min(ans, cnt);
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}