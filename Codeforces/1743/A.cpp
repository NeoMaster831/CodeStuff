#include <bits/stdc++.h>

using namespace std;

int N; bool A[10];

void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int dummyinp; cin >> dummyinp;
    }

    int combis = (10 - N) * (10 - N - 1) / 2;
    cout << combis * 6 << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}