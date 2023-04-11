#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, M;
string S[1001];

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    set<pair<char, pair<char, char> > > s;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }

    int ans = 0;
    for (int i = 1; i <= M; i++) {
        string inp; cin >> inp;
        pair<char, pair<char, char> > pc = { inp[0], {inp[1], inp[2]}};
        s.insert(pc);
    }

    for (int i = 1; i <= N; i++) {
        pair<char, pair<char, char> > tofind = {S[i][3], {S[i][4], S[i][5]}};
        auto x = s.find(tofind);
        if (x != s.end()) ans++;
    }

    cout << ans << '\n';
}