#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, a[1001];

vector<int> factorize(int n) {
    vector<int> factors;

    // Extract all 2's from the number
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Check for odd factors
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}

void solve() {
    cin >> n;

    map<int, int> m;
    for (int i =1 ; i <= n; i++) {
        cin >> a[i];
        auto factors = factorize(a[i]);
        for (int i = 0; i < factors.size(); i++) {
            auto x = m.find(factors[i]);
            if (x != m.end()) {
                x->second++;
            } else {
                m.insert({factors[i], 1});
            }
        }
    }

    int ans = 0;
    int left = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        ans += iter->second / 2;
        left += iter->second % 2;
    }

    cout << ans + left / 3 << '\n';

}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
}