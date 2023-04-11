#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[20];

int gcd(int a, int b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}
void solve() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 99999222299999;
    for (int k = 0; k < (1 << N); k++) {

        bool can = false;

        int g = A[0];
        for (int i = 0; i < N; i++) {

            int f;
            if (k & (1 << i)) f = i + 1;
            else f = A[i];

            if (gcd(g, f) == 1) can = true;
        }

        if (!can) continue;
        
        int cost = 0;
        for (int i = 0; i < N; i++) {
            if (k & (1 << i)) cost += N - i;
        }

        ans = min(cost, ans);
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}