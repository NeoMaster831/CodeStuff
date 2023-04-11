#include <bits/stdc++.h>

using namespace std;

void solve() {

    int N; cin >> N;
    set<int> s, tw;
    bool y = false;

    vector<vector<int> > a;
    for (int j = 0; j < N; j++) {
        int k; cin >> k; vector<int> inp;
        for (int i = 0; i < k; i++) {
            int p; cin >> p;
            inp.push_back(p);
            auto it = s.find(p);
            if (it != s.end()) {
                tw.insert(p);
            }
            s.insert(p);
        }

        a.push_back(inp);
    }

    for (int i = 0; i < a.size(); i++) {

        bool allfound = true;
        for (int j = 0; j < a[i].size(); j++) {
            auto it = tw.find(a[i][j]);
            if (it == tw.end()) allfound = false;
        }

        if (allfound) y = true;
    }

    if (y) cout << "YES" << '\n';
    else cout << "NO" << '\n';

}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}