#include <iostream>

using namespace std;
#define int long long
#define INF 98765432123456

int N, b[301][301], ans[301];

signed main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            cin >> b[i][j];
        }
    }
    
    ans[1] = 0;
    for (int i = 1; i < N; i++) {
        ans[i + 1] = ans[i] + b[i][i + 1];
        
        int mx = -INF, mn = INF;
        for (int j = 1; j <= i + 1; j++) {
            mx = max(mx, ans[j]); mn = min(mn, ans[j]);
            if (mx - mn != b[1][j]) {
                ans[i + 1] = ans[i] - b[i][i + 1];
                break;
            }
        }

    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }
}