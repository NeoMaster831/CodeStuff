#include <bits/stdc++.h>

using namespace std;
#define int long long

int f, s, N;

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        string inp; cin >> inp;
        if (inp == "For") f++;
        else s++;
    }

    if (f > s) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}