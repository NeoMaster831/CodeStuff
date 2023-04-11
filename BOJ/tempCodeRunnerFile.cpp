#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, jim[1001], perm[1001];
pair<int, int> s[1001];
bool chk[1001];

pair<int, pair<int, int> > dfs(int idx, int mini) { // size, min, sum
    if (chk[idx]) {
        return { 0, { mini, 0 } };
    }
    chk[idx] = true;
    int nxt = perm[idx];
    pair<int, pair<int, int> > val = dfs(nxt, min(mini, jim[nxt]));
    val.second.second += jim[idx];
    val.first++;
    return val;
}

signed main() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> jim[i];
    }
    for (int i = 1; i <= N; i++) {
        s[i] = { jim[i], i };
    }
    sort(s + 1, s + N + 1);

    for (int i = 1; i <= N; i++) {
        perm[s[i].second] = i;
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        pair<int, pair<int, int> > ret = dfs(i, jim[i]);
        
        int sz = ret.first;
        int mini = ret.second.first;
        int sum = ret.second.second;

        if (sz <= 1) continue;
        ans += sum + mini * (sz - 2);
    }

    cout << ans << '\n';
    
}