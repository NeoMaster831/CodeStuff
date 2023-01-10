#include <bits/stdc++.h>

using namespace std;

int N;

void solve() {
    
    cin >> N;

    if (N % 2 == 0) {

        int middle = N / 2;

        for (int i = N / 2; i >= 1; i--) {
            cout << i << ' ' << i + middle << ' ';
        }

    } else {

        int middle = N / 2 + 1;
        for (int i = 1; i <= N / 2; i++) {
            cout << i << ' ' << i + middle << ' ';
        }

        cout << middle;
    }

    cout << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}