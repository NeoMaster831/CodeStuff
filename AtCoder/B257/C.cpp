#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, psum[200001][2];
string S;
bool info[200001];
vector<pair<int, int> > W;

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    cin >> S;
    for (int i = 0; i < N; i++) {
        info[i + 1] = S[i] - 48;
    }

    for (int i = 1; i <= N; i++) {
        int inp; cin >> inp;
        W.push_back({inp, !info[i]});
    }

    sort(W.begin(), W.end());
    
    psum[0][0] = W[0].second;
    for (int i = 1; i < W.size(); i++) {
        psum[i][0] = psum[i - 1][0] + W[i].second;
    }

    psum[N - 1][1] = !W[N - 1].second;
    for (int i = N - 2; i >= 0; i--) {
        psum[i][1] = psum[i + 1][1] + !W[i].second;
    }

    int ans = 0;
    for (int i = 0; i < W.size(); i++) {
        ans = max(ans, psum[i][0] + psum[i][1]);
    }

    cout << ans << '\n';
}