#include <bits/stdc++.h>
 
using namespace std;
 
int N, A[100001];
 
int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
 
void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
 
    bool ans = true;
    for (int i = 1; i <= N - 2; i++) {
        if (A[i + 1] % gcd(A[i], A[i + 2]) != 0) ans = false;
    }
 
    if (ans) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
 
int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    int T; cin >> T;
    while (T--) solve();
}