#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N; cin >> N;
    cout << ((N % 2 == 0) ? N / 2 : N / 2 + 1) << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}