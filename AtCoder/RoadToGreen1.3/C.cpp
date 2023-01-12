#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, X;
vector<int> L[100001];

int solve(int idx, int left) {

    if (idx == N + 1 && left == 1) {
        return 1;
    }

    int res = 0;
    for (int i = 0; i < L[idx].size(); i++) {
        int a = L[idx][i];
        if (left % a != 0) continue;
        res += solve(idx + 1, left / a);
    }

    return res;
}

signed main() {

    cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        int l; cin >> l;
        for (int j = 0; j < l; j++) {
            int inp; cin >> inp;
            L[i].push_back(inp);
        }
    }

    cout << solve(1, X) << '\n';
}