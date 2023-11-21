#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        a %= 10;
        vector<int> jari;
        int last = a;
        jari.push_back(last);
        while (true) {
            last = (last * a) % 10;
            if (last == a) break;
            jari.push_back(last);
        }

        cout << jari[(b-1) % jari.size()] + (jari[(b-1) % jari.size()] % 10 == 0) * 10 << '\n';
    }

}