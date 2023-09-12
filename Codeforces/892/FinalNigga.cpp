#include <bits/stdc++.h>

using namespace std;
#define int long long

int n;

void solve() {
    cin >> n;

    int maxi = 0;
    for (int i = n; i >= 1; i--) {
        
        int cnt = 0;
        int ans = 0;
        int premax = 0;
        for (int j = n; j >= 1; j--) {
            if (j >= i) {
                ans += j * (i + cnt);
                premax = max(premax, j * (i + cnt));
                cnt++;
            } else {
                ans += j * j;
            }
        }
        //cout << i << ' ' << ans-premax << '\n';
        maxi = max(maxi, ans- premax);
    }

    cout << maxi << '\n';
}



signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}