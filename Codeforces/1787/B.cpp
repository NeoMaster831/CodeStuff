#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pp pair<int, int>

int N;

void solve() {

    cin >> N;

    int t = N;
    vector<pp> factor;
    for (int i = 2; i * i <= t; i++) {

        int exp = 0;
        while (N % i == 0) {
            N /= i;
            exp++;
        }
        if (exp != 0) factor.push_back({ i, exp });
    }
    if (N != 1) {
        factor.push_back({N, 1});
    }

    int to_mul = 1;
    priority_queue<pp, vector<pp>, greater<pp> > pq;
    for (int i = 0; i < factor.size(); i++) {
        to_mul *= factor[i].first;
        pq.push({factor[i].second, factor[i].first});
    }

    int to_sub = 0, ans = 0;
    while (!pq.empty()) {
        int exp = pq.top().first;
        ans += (exp - to_sub) * to_mul;
        to_sub += (exp - to_sub);
        while (!pq.empty() && pq.top().first == exp) {
            to_mul /= pq.top().second;
            pq.pop();
        }
        //cout << to_mul << ' ' << to_sub << '\n';
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}