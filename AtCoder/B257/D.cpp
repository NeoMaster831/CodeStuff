#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 98765432123

int N, power[206];
pair<int, int> coords[206];

bool solve(int train) {

    int floyd[206][206];
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) floyd[i][j] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int PiS = power[i] * train;
            int a1 = abs(coords[i].first - coords[j].first);
            int a2 = abs(coords[i].second - coords[j].second);
            if (PiS >= a1 + a2) floyd[i][j] = 0;

        }
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }

    bool ans = false;
    for (int i = 1; i <= N; i++) {
        bool subans = true;
        for (int j = 1; j <= N; j++) {
            if (floyd[i][j] != 0) subans = false;
        }
        if (subans) ans = true;
    }

    return ans;
}

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x, y, z; cin >> x >> y >> z;
        coords[i] = {x, y}; power[i] = z;
    }

    int l = 0, r = MAX;

    int ans = r;
    while (l <= r) {
        int m = (l + r) / 2;

        //cout << "Left: " << l << ", Right: " << r << ", middle: " << m << ", SolveAns?: " << solve(m) << '\n';
        if (solve(m)) { // if can with power m
            ans = min(m, ans);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans << '\n';
}