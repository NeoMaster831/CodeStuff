#include <bits/stdc++.h>

using namespace std;

int N;

void solve() {
    cin >> N;

    int remainder = (N - 4) % 3;
    if (remainder == 0 || remainder == 1) {
        cout << (N - 4) / 3 - 1;
    } else cout << (N - 4) / 3;
    cout << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}