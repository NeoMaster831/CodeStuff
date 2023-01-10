#include <bits/stdc++.h>

using namespace std;

int N, K, arr[100001];

void solve() {

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int A = 0, val = 1;
    for (int i = 1; i <= N; i++) {
        if (arr[i] == val) { val++; A++; }
    }

    int ht = N - A;
    if (ht % K) cout << ht / K + 1 << '\n';
    else cout << ht / K << '\n';
}

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T; cin >> T;
    while (T--) solve();
}