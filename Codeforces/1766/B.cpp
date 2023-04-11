#include <bits/stdc++.h>

using namespace std;
#define int long long

int N;
string S;

void solve() {
    
    cin >> N >> S;

    set<pair<char, char> > se;
    bool ans = false;
    for (int i = 0; i < N - 1; i++) {
        
        pair<char, char> subst = { S[i], S[i + 1] };
        auto x = se.find(subst);
        if (x != se.end()) {
            ans = true; break;
        }
        if (i != 0) se.insert({S[i - 1], S[i]});
    }

    if (ans) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}