#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, M;
string S;
int firsts[2400001];

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    cin >> S;
    S = "*" + S;

    for (int i = 1; i <= N; i++) {
        int inp; cin >> inp;
        if (inp > M) continue;
        if (firsts[inp] == 0) {
            firsts[inp] = i;
        } else {
            swap(S[i], S[firsts[inp]]);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << S[i];
    }
    cout << '\n';

}