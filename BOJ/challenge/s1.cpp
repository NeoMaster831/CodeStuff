#include <bits/stdc++.h>

using namespace std;
#define int long long

int dfs(int x, int y, int depth) {

    if (depth == 0) return 0;
    int cutlane = (int)pow(2.0f, (float)(depth - 1));

    int area = 0;
    if (x >= cutlane) {
        x -= cutlane;
        area += 2;
    }
    if (y >= cutlane) {
        y -= cutlane;
        area++;
    }

    int addwhat = (int)pow(2.0f, (float)(2 * (depth - 1))) * area;
    //cout << area << ' ' << addwhat << '\n';
    return addwhat + dfs(x, y, depth - 1);

}

signed main() {
    int n, r, c; cin >> n >> r >> c;
    cout << dfs(r, c, n) << '\n';
}