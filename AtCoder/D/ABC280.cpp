#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 10LL

int K;
bool chk[MAX + 1];

signed main() {

    cin >> K;

    int wonlaeK = K;
    int ans = 0;
    for (int i = 2; i <= MAX; i++) {

        int t = 1; while (t <= MAX) { t *= i; }
        t /= i;
        
        while (t != 1) {
            chk[t] = true;
            if (K % t != 0) { t /= i; continue; }
            ans = max(ans, t);
            K /= t;
            t /= i;
        }

        if (K == 1) break;
    }

    if (ans == 0) cout << wonlaeK << '\n';
    else cout << ans << '\n';

}