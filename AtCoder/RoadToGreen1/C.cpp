#include <bits/stdc++.h>

using namespace std;
#define int long long

bool isJegob(int x) {
    if (sqrt(x) - (int)(sqrt(x)) == 0) {
        return true;
    }
    return false;
}

void solve(int n) {

    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {

            int A = i, B = j;
            int CJegob = 2 * n - A * A - B * B;
            if (!isJegob(CJegob)) continue;
            int C = (int)sqrt(CJegob);

            if (A <= 0 || B <= 0 || C <= 0) continue;
            if (A + C - B <= 0) continue;
            if ((A + C - B) % 2 == 1) continue;
            int x = (A + C - B) / 2;
            int y = A - x;
            int z = C - x;
            if (x < 1 || y < 1 || z < 1) continue;

            ans++;
        }
    }

    cout << ans << '\n';
}

signed main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        solve(i);
    }
}