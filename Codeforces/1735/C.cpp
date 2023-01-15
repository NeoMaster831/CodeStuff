#include <bits/stdc++.h>

using namespace std;

int N, A[100001];
pair<int, int> parent[27]; string S;
string D = "abcdefghijklmnopqrstuvwxyz";

void Union(int from, int to) {
    parent[to] = { parent[from].first, parent[from].second + 1 };
}

void solve() {
    
    cin >> N;
    cin >> S;
    for (int i = 0; i < S.size(); i++) {
        A[i + 1] = S[i] - 96;
    }

    for (int i = 1; i <= 26; i++) {
        parent[i] = { i, 1 };
    }

    for (int i = 1; i <= N; i++) {

        int val = A[i];
        if (parent[val].first != val) {
            cout << D[parent[val].first - 1];
        }
        for (int j = 1; j <= 26; j++) {
            if (parent[j].first == j) { // not connected
                
            }
        }

    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}