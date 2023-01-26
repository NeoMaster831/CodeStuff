#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    
    if (A == 0 && C == 0) { cout << 0 << '\n'; return; }
    else if (A == 0 || C == 0) { cout << 1 << '\n'; return; }

    if (max(B, D) % min(B, D) != 0) {
        cout << 2;
    } else {
        if (B >= D) {
            int div = B / D;
            if (C * div == A) cout << 0;
            else if (max(A, C * div) % min(A, C * div) == 0) cout << 1;
            else cout << 2;
        } else {
            int div = D / B;
            if (A * div == C) cout << 0;
            else if (max(A * div, C) % min(A * div, C) == 0) cout << 1;
            else cout << 2;
        }
    }

    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}