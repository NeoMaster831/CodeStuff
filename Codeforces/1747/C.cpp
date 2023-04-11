#include <bits/stdc++.h>

using namespace std;

int N, A[100001];

void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int a1 = A[1];
    for (int i = 1; i <= N; i++) {
        if (A[i] < a1) { cout << "Alice" << '\n'; return; }
    }
    cout << "Bob" << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}