#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define MAX 1000000000
 
int N;
 
void solve() {
    
    cin >> N;
    if (N % 2 == 1) { cout << -1 << '\n'; return; }
    cout << N / 2 << ' ' << 1 << '\n';
}
 
signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}