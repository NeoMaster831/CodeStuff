#include <bits/stdc++.h>

using namespace std;
#define int long long

int K, A, B;

signed main() {

    cin >> K >> A >> B;
    
    if (K - A + 1 <= 0 || B - A < 2) {
        cout << K + 1 << '\n'; return 0;
    }

    int ans = A;
    K -= A - 1;
    ans += (K % 2) + (K / 2) * (B - A);

    cout << ans << '\n';
}