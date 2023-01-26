#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, A[200001], psum[200001][2];

int gcd(int a, int b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

void solve() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    psum[1][0] = A[1];
    for (int i = 2; i <= N; i++) {
        psum[i][0] = psum[i - 1][0] + A[i];
    }
    psum[N][1] = A[N];
    for (int i = N - 1; i >= 1; i--) {
        psum[i][1] = psum[i + 1][1] + A[i];
    }

    int ans = 0;
    for (int i = 1; i <= N - 1; i++) {
        int fir = psum[i][0];
        int sec = psum[i + 1][1];
        ans = max(ans, gcd(fir, sec));
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}