#include <bits/stdc++.h>

using namespace std;
#define int long long
#define x first
#define y second

void solve() {
    pair<int, int> A, B, C;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    if (A.x <= C.x && A.y <= C.y) { // 1사분면
        B.x = max(A.x, B.x); B.y = max(A.y, B.y);
        cout << abs(A.x - min(B.x, C.x)) + abs(A.y - min(B.y, C.y)) + 1 << '\n';
    } else if (A.x >= C.x && A.y >= C.y) { // 3사분면
        B.x = min(A.x, B.x); B.y = min(A.y, B.y);
        cout << abs(A.x - max(B.x, C.x)) + abs(A.y - max(B.y, C.y)) + 1 << '\n';
    } else if (A.x <= C.x && A.y >= C.y) {
        B.x = max(A.x, B.x); B.y = min(A.y, B.y);
        cout << abs(A.x - min(B.x, C.x)) + abs(A.y - max(B.y, C.y)) + 1 << '\n';
    } else if (A.x >= C.x && A.y <= C.y) {
        B.x = min(A.x, B.x); B.y = max(A.y, B.y);
        cout << abs(A.x - max(B.x, C.x)) + abs(A.y - min(B.y, C.y)) + 1 << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}