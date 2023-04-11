#include <bits/stdc++.h>

using namespace std;

string S;

int main() {

    cin >> S;

    int cnt = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '0' && S[i + 1] == '0') i++;
        cnt++;
    }

    cout << cnt << '\n';
}