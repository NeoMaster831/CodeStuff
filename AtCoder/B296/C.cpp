#include <bits/stdc++.h>

using namespace std;
#define int long long

int N, X, A[200001];

signed main() {

    cin >> N >> X;

    set<int> s;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        s.insert(A[i]);
    }

    bool ans = false;
    for (int i = 1; i <= N; i++) {
        ans |= (s.find(X + A[i]) != s.end());
    }

    cout << (ans ? "Yes" : "No") << '\n';
}