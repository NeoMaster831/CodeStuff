#include <bits/stdc++.h>

using namespace std;

int N, ans[51][51];

void solve() {
    cin >> N;

    int now = 1, modifier = N * N - 1;
    bool plusorminus = true;
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 1) {
            for (int j = 1; j <= N; j++) {
                ans[i][j] = now;
                if (plusorminus) now += modifier;
                else now -= modifier;
                modifier--;
                plusorminus = !plusorminus;
            }
        }
        else {
            for (int j = N; j >= 1; j--) {
                ans[i][j] = now;
                if (plusorminus) now += modifier;
                else now -= modifier;
                modifier--;
                plusorminus = !plusorminus;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}