#include <bits/stdc++.h>

using namespace std;

int N; string Dialog;
int st;

void solve() {

    cin >> N >> Dialog;

    int st = 0;
    for (int i = 0; i < N; i++ ) {
        if (Dialog[i] == 'Q') st++;
        if (Dialog[i] == 'A') { st--; if (st < 0) st = 0; }
    }

    if (st == 0) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}