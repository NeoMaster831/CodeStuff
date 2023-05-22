#include <bits/stdc++.h>

using namespace std;
#define int long long
#define INF 987654321234567

int N;

signed main() {

    cin >> N;

    int ans = 0, mini = INF, cnt = 0;
    for (int i = 1; i <= N; i++) {
        int inp; cin >> inp;
        ans += inp;
        if (inp % 2) {
            mini = min(inp, mini);
            cnt++;
        }
    }

    if (mini != INF && cnt % 2 == 1) ans -= mini;

    cout << ans << '\n';
}