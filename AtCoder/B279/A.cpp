#include <bits/stdc++.h>

using namespace std;
#define int long long

string S;

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> S;

    int ans = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'v') ans++;
        else ans += 2;
    }    

    cout << ans << '\n';
}