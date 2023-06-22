#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, M;
int dp[5002][5002][2]; // i ~ j이고 내가 지금 0=왼쪽,1=오른쪽에 있을 때 버틸수있는최댓값
vector<pair<int, int> > a;

int solve(int left, int right, bool state, int how) { // 0=왼쪽, 1=오른쪽
    
    int& cache = dp[left][right][state];
    if (how <= 0 && left != right) return cache = 0;
    if (cache != -1) return cache;
    
    how += state ? a[right].second : a[left].second;
    if (left == 0 && right == a.size() - 1) return cache = how;

    int ans = 0;
    if (state == 1) {
        int l = 0, r = 0;
        if (left - 1 >= 0) l = solve(left - 1, right, 0, how - (a[right].first - a[left - 1].first)) + min(how, (a[right].first - a[left - 1].first));
        if (right + 1 < a.size()) r = solve(left, right + 1, 1, how - (a[right + 1].first - a[right].first)) + min(how, (a[right + 1].first - a[right].first));
        ans = max(l, r);
    } else { // 왼쪽
        int l = 0, r = 0;
        if (left - 1 >= 0) l = solve(left - 1, right, 0, how - (a[left].first - a[left - 1].first)) + min(how, (a[left].first - a[left - 1].first));
        if (right + 1 < a.size()) r = solve(left, right + 1, 1, how - (a[right + 1].first - a[left].first)) + min(how, (a[right + 1].first - a[left].first));
        ans = max(l, r);
    }

    return cache = ans;
}

signed main() {
    
    cin >> N >> M;
    a.push_back({0, M});
    for (int i = 1; i <= N; i++) {
        int x, p; cin >> x >> p;
        a.push_back({x, p});
    }

    sort(a.begin(),a.end());
    memset(dp, -1, sizeof(dp));

    int idx = -1;
    for (int i = 0; i < a.size(); i++) {
        if (a[i].first == 0) idx = i;
    }
    
    cout << solve(idx, idx, 0, 0) << '\n';
}