#include <bits/stdc++.h>

using namespace std;

int N; string s;

void solve() {
    
    N = 0; s.clear();
    cin >> N >> s;


    bool one = false;
    bool zero = false;
    for (int i = 0; i < N - 1; i++) {
        if (s[i] == 'L' && s[i + 1] == 'R') one = true;
        if (s[i] == 'R' && s[i + 1] == 'L') zero = true;
    }

    if (zero == true) { cout << 0 << '\n'; return; }
    if (one == true) { cout << 1 << '\n'; return; }
    cout << -1 << '\n'; return;
}

int main() {
    int T; cin >> T;
    while (T--) solve();
}