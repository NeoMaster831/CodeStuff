#include <bits/stdc++.h>

using namespace std;

string s;
int b[300001];

void solve() {
    
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        b[i] = !(s[i] - 97);
    }

    if ((b[0] == b[1] && b[0] == 1) || b[0] < b[1]) {
        cout << s[0] << ' ' << s[1] << ' ';
        for (int i = 2; i < s.size(); i++) {
            cout << s[i];
        }
        cout << '\n';
    }
    else {
        cout << s[0] << ' ';
        for (int i = 1; i < s.size() - 1; i++) {
            cout << s[i];
        }
        cout << ' ' << s[s.size() - 1] << '\n';
    }

}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}