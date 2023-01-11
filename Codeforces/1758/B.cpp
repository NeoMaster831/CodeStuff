#include <bits/stdc++.h>

using namespace std;

int N;

void solve() {

    cin >> N;
    if (N % 2 == 1) {
        for (int i = 1; i <= N; i++) cout << 1 << ' ';
    }
    else {
        cout << "1 3 ";
        for (int i = 3; i <= N; i++) {
            cout << 2 << ' ';
        }
    }
    cout << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}