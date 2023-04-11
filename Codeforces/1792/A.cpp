#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, H[101];

void solve() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }

    int fir = 0, sec = 0;
    for (int i = 1; i <= N; i++) {
        if (H[i] > 2) sec++;
        else fir += H[i];
    }

    fir = (fir / 2) + (fir % 2);
    cout << sec + fir << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}