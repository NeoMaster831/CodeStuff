#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pp pair<int, int>

int n, k;

bool cmp(pp left, pp right) {
    if (left.first == right.first) return left.second < right.second;
    else return left.first > right.first;
}

void solve() {

    cin >> n >> k;
    vector<pp> v;
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp;
        if (inp % k == 0) v.push_back({k, i});
        else v.push_back({inp % k, i});
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) cout << v[i].second << ' ';
    cout << '\n';

}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}