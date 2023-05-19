#include <bits/stdc++.h>

using namespace std;
#define int long long

int N;
string S;

signed main() {
    
    cin >> N >> S;
    
    char c = S[0];
    for (int i = 1; i < S.size(); i++) {
        if (c == S[i]) { cout << "No" << '\n'; return 0; }
        c = S[i];
    }

    cout << "Yes" << '\n';
}