#include <bits/stdc++.h>

using namespace std;

string s;

int main() {

    cin >> s;

    int l = 0, r = s.size() - 1;

    int ans = 0;
    while (l <= r) {

        if (s[l] != s[r]) {
            ans++;
        }

        l++; r--;
    }

    cout << ans << '\n';
}