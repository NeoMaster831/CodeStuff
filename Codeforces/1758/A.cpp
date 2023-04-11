#include <bits/stdc++.h>

using namespace std;

string s;

void solve() {
    
    cin >> s;
    cout << s;
    for (int i = s.size() - 1; i >= 0; i--) {
        cout << s[i];
    }
    cout << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}