#include <bits/stdc++.h>

using namespace std;
#define int long long

int gcd(int x, int y){

    if(y == 0){

        return x;

    } else {

        return gcd(y, x%y);

    }

}

void solve() {
    int n;
    cin >> n;

    int gc = -1;
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp;
        int diff = abs(inp - i);
        if (diff == 0) continue;
        if (gc == -1) {
            gc = diff; continue;
        }
        gc = gcd(gc, diff);
    }

    cout << gc << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}