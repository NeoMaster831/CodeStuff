#include <bits/stdc++.h>

using namespace std;
#define int long long

int W, D, H, a, b, f, g;

void solve() {
    
    cin >> W >> D >> H >> a >> b >> f >> g;

    // 1. 오른쪽
    int right = (W - f) + (W - a) + H + abs(b - g);
    // 2. 왼쪽
    int left = f + a + H + abs(b - g);
    // 3. 아래
    int bottom = b + g + H + abs(a - f);
    // 4. 위
    int top = (D - b) + (D - g) + H + abs(a - f);

    cout << min({right, left, bottom, top}) << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}