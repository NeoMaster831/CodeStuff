#include <bits/stdc++.h>

using namespace std;
#define int long long

int K, N;
bool dislike[101];

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    priority_queue<pair<int, int> > A;
    for (int i = 1; i <= N; i++) {
        int inp; cin >> inp;
        A.push({inp, i});
    }


    for (int i = 1; i <= K; i++) {
        int inp; cin >> inp;
        dislike[inp] = true;
    }

    pair<int, int> t = A.top();
    bool ans = dislike[t.second];
    int maxi = t.first;
    A.pop();

    while (!A.empty()) {
        pair<int, int> id = A.top(); A.pop();
        //cout << maxi << ' ' << id.first << ' ' << id.second << '\n';
        if (maxi != id.first) break;
        if (dislike[id.second]) ans = true;
    }


    if (ans) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}