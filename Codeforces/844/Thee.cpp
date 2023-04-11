#include <bits/stdc++.h>

using namespace std;
#define int long long

int clsqrt(int x) {
    return ceil(sqrt(x));
}

int N, A[51];

void solve() {
    
    set<int> s;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        s.insert(A[i]);
    }

    for (int i = 1;)
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}