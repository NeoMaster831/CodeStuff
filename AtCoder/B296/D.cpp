#include <bits/stdc++.h>

using namespace std;
#define int long long
#define INF 9876543212345678

int N, M;

signed main() {

    cin >> N >> M;
    int l = 1, r = N;

    int ans = INF;
    while (l <= r) {

        int product = l * r;
        if (product >= M) ans = min(ans, product);

        if (product < M) l++;
        else r--;
        
    }

    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
}