#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N; cin >> N; int A[101];

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i]; ans += (A[i] % 2);
    }

    cout << ans << '\n';
}

int main() {
    int T; cin >> T; while (T--) {
        solve();
    }
}