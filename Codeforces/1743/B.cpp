#include <bits/stdc++.h>

using namespace std;

void solve() {
    
    int N; cin >> N;
    cout << 1 << ' ';
    for (int i = N; i >= 2; i--) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}