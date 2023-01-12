#include <bits/stdc++.h>

using namespace std;

int N, cnt[100001];

int main() {
    
    cin >> N;
    for (int i = 1; i <= 4 * N - 1; i++) {
        int inp; cin >> inp;
        cnt[inp]++;
    }

    for (int i = 1; i <= N; i++) {
        if (cnt[i] != 4) {
            cout << i << '\n';
            return 0;
        }
    }
}