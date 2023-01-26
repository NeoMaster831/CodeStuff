#include <bits/stdc++.h>

using namespace std;
#define int long long

int A, B, C, D;

void solve() {

    cin >> A >> B >> C >> D;

    int ans = A;
    if (A == 0) {
        cout << ans + 1 << '\n'; return;
    }

    if (B >= C) {
        
        ans += C * 2;
        B -= C;
        if (A - B < 0) { // become -1
            ans += A + 1;
        } else {
            ans += B;
            A -= B;
            if (A - D < 0) {
                ans += A + 1;
            } else {
                ans += D;
            }
        }

    } else {

        ans += B * 2;
        C -= B;

        if (A - C < 0) {
            ans += A + 1;
        } else {
            ans += C;
            A -= C;
            if (A - D < 0) {
                ans += A + 1;
            } else {
                ans += D;
            }
        }

    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}