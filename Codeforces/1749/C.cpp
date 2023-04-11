#include <bits/stdc++.h>

using namespace std;

int N, A[101];

bool solution(int rounds) {

    int idx = lower_bound(A + 1, A + N + 1, rounds) - A;
    if (A[idx] > rounds) return false;
    if (idx > N) return false;

    for (int i = 1; i <= rounds; i++) {
        int stage = rounds - i + 1;
        int radix = idx - (i - 1) * 2;
        
        if (radix <= 0) return false;
        int can = lower_bound(A + 1, A + radix, stage) - A;
        if (can > radix) return false;
    }

    return true;

}

void solve() {

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    sort(A + 1, A + N + 1);

    int l = 1, r = 100, ans = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (solution(m)) { // can!
            l = m + 1;
            ans = max(ans, m);
        }
        else {
            r = m - 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}