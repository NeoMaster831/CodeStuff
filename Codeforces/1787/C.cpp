#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, S, A[200001];
pair<int, int> optimal[200001];

void solve() {
    
    cin >> N >> S;
    for (int i = 1; i <= N; i++) cin >> A[i];

    if (N % 2 == 0) {
        
        
        for (int i = 2; i <= N / 2; i++) {
            if (A[i] < S * 2) {
                optimal[i] = { S - A[i], S };
            }
        }



    } else {

    }
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}