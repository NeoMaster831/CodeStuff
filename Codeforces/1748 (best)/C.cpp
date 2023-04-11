#include <bits/stdc++.h>

using namespace std;

// This is the both solution of C1 and C2.

int N, arr[200001];
bool o[200001];

void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int now = arr[1]; o[1] = true;
    for (int i = 2; i <= N; i++) {
        if (now + arr[i] > 1 || now + arr[i] < -1) {
            now -= arr[i]; o[i] = false;
        }
        else {
            now += arr[i]; o[i] = true;
        }
    }

    if (now != 0) { cout << -1 << '\n'; return; }

    vector<pair<int, int> > ans;
    for (int i = 1; i <= N; i++) {
        if (o[i] == true && o[i + 1] == false && i != N) {
            ans.push_back({ i, i + 1 });
            i++;
            continue;
        } else if (o[i] == false) continue;
        else ans.push_back({ i, i });
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}

int main() {

    int T; cin >> T;
    while (T--) solve();
}