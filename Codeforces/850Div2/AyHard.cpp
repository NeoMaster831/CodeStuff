#include <bits/stdc++.h>

using namespace std;
#define int long long

int N;

void solve() {
    
    cin >> N;

    // 0 is white, 1 is black
    int togive = 1; bool who = true;
    int Alice[2] = { 0, 0 }, Bob[2] = { 0, 0 };
    while (N > 0) {
        
        if (N - togive < 0) {
            togive = N;
        }

        //cout << togive << '\n';
        int r = 1;
        if (togive % 2 == 0) r = 0;

        if (who) {
            Alice[0] += togive / 2 + r;
            Alice[1] += togive / 2;
        } else {
            Bob[0] += togive / 2;
            Bob[1] += togive / 2 + r;
        }

        who = !who;
        N -= togive;
        togive += 4;
    }

    cout << Alice[0] << ' ' << Alice[1] << ' ' << Bob[0] << ' ' << Bob[1] << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}