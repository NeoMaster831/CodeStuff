#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {

    int s = 4271010253;
    for (int i = 2; i * i <= s; i++) {
        if (s % i == 0) {
            cout << i << ' ' << s / i << '\n';
        }
    }
}