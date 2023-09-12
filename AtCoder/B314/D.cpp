#include <bits/stdc++.h>

using namespace std;
#define int long long

int N;
string S;
int Q;
queue<pair<int, pair<int, int> > > queries;

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    cin >> S;
    cin >> Q;
    pair<int, int> maxi = { 9876543234567, 1 };
    for (int i = 1; i <= Q; i++) {
        int t, x; char c;
        cin >> t >> x >> c;
        if (t == 1) queries.push({i, {x, c}});
        else {
            maxi = make_pair(i, t);
        }
    }

    bool did = false;
    pair<int, pair<int, int> > query;
    while (!queries.empty()) {

        query = queries.front(); queries.pop();

        if (query.first >= maxi.first && !did) {
            if (maxi.second == 2) {
                for (int i = 0; i < N; i++) if (S[i] < 97) S[i] += 32;
            } else {
                for (int i = 0; i < N; i++) if (S[i] >= 97) S[i] -= 32;
            }
            did = true;
        }
        int x = query.second.first;
        int c = query.second.second;
        S[x - 1] = c;

    }
    if (query.first < maxi.first && !did && maxi.first != 9876543234567) {
        if (maxi.second == 2) {
            for (int i = 0; i < N; i++) if (S[i] < 97) S[i] += 32;
        } else {
            for (int i = 0; i < N; i++) if (S[i] >= 97) S[i] -= 32;
        }
        did = true;
    }
    cout << S << '\n';
    
}