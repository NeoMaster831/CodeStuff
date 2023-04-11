#include <bits/stdc++.h>

using namespace std;
#define int long long

int N;

void solve() {
    
    cin >> N;

    int togive = 1; bool who = true;
    int Alice = 0, Bob = 0;
    while (N > 0) {
        
        if (N - togive < 0) {
            togive = N;
        }

        if (who) {
            Alice += togive;
        }else {
            Bob += togive;
        }
        who = !who;
        N -= togive;
        togive += 4;
    }

    cout << Alice << ' ' << Bob << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}