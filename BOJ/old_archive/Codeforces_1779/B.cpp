#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N; cin >> N;
    if (N % 2 == 1) { cout << "NO" << '\n'; return; }
    else {
        cout << "YES" << '\n';
        int x = 1;
        for (int i = 1; i <= N; i++) {
            cout << x << ' ';
            x = -x;
        }
        cout << '\n';
    }
}

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}