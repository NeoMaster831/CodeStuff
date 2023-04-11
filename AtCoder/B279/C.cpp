#include <bits/stdc++.h>

using namespace std;
#define int long long

int H, W, K[4000001], L[4000001];

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        string inp; cin >> inp;
        for (int j = 0; j < W; j++) {
            if (inp[j] == '.') K[i]++;
        }
    }

    for (int i = 1; i <= H; i++) {
        string inp; cin >> inp;
        for (int j = 0; j < W; j++) {
            if (inp[j] == '.') L[i]++;
        }
    }

    bool ans = true;
    for (int i = 1; i <= H; i++) {
        if (K[i] != L[i]) ans = false;
    }

    if (ans) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}