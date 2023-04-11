#include <bits/stdc++.h>

using namespace std;
#define int long long

int L, R;

void solve() {
    cin >> L >> R;

    int Lg = sqrt(L);
    int Rg = sqrt(R);

    int ans = max(0LL, Rg - Lg - 1) * 3;

    if (Lg * Lg >= L && Lg * Lg <= R) ans++;
    if ((Lg + 1) * Lg >= L && (Lg + 1) * Lg <= R) ans++;
    if ((Lg + 2) * Lg >= L && (Lg + 2) * Lg <= R) ans++;
    
    if (Lg != Rg) {
        if (Rg * Rg >= L && Rg * Rg <= R) ans++;
        if ((Rg + 1) * Rg >= L && (Rg + 1) * Rg <= R) ans++;
        if ((Rg + 2) * Rg >= L && (Rg + 2) * Rg <= R) ans++;
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}