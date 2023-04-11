#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, X;
string S = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> X;
    
    if (X % N == 0) cout << S[X / N - 1] << '\n';
    else cout << S[X / N] << '\n';
}