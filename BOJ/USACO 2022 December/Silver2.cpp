#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAX 5000000LL

int N, A[200001], john[200001];
bool habsung[MAX + 1];

void erathos() {
    for (int i = 2; i <= MAX; i++) {
        if (!habsung[i]) {
            for (int j = i * 2; j <= MAX; j += i) {
                habsung[j] = true;
            }
        }
    }
}

void solve() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int mini = 987654321234567;
    for (int i = 1; i <= N; i++) {
        // if Even:
        if (A[i] % 2 == 0) {
            john[i] = A[i] / 2;
        }
        else {
            if (habsung[A[i]]) john[i] = 3;
            else john[i] = 1;
        }
        if (mini / 2 > john[i] / 2) mini = john[i];
    }

    if (mini % 2 == 0) cout << "Farmer Nhoj" << '\n';
    else cout << "Farmer John" << '\n';
    
}

signed main() {
    erathos();
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T; while (T--) solve();
}