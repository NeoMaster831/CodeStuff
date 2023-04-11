#include <bits/stdc++.h>

using namespace std;
#define int long long

int N; string S;

signed main() {

    cin >> N >> S;
    for (int i = 1; i <= N - 1; i++) {

        int maxi = 0;
        for (int j = 1; j <= N - i; j++) {
            if (S[j - 1] == S[j + i - 1]) break;
            maxi++;
        }

        cout << maxi << '\n';
    }
}