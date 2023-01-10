#include <bits/stdc++.h>

using namespace std;
#define pi pair<int, int>

int N, arr[200001];
set<pi> s;

void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        s.insert({arr[i], i});
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {

        auto ptr = s.begin();
        int val = (*ptr).first;
        int idx = (*ptr).second;

        s.erase({val, idx});
        if (idx == i) {
            continue;
        }

        int to_swap = arr[i];
        s.erase({to_swap, i});
        s.insert({to_swap, idx});
        cnt++;
    }

    cout << cnt << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}