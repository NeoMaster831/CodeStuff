#include <bits/stdc++.h>

using namespace std;
#define int long long

string S, T;

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> S >> T;
    
    bool ans = false;
    for (int i = 0; i < S.size(); i++) {
        
        bool subans = true;
        for (int j = 0; j < T.size(); j++) {
            if (S[i + j] != T[j]) subans = false;
        }

        ans |= subans;
    }

    if (ans) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}