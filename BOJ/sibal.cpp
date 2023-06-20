#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int x, k; cin >> x >> k;
    if (x == 0) {
        cout << 0 << '\n';
        return 0;
    }
    bool eumsu = x < 0;
    if (eumsu) x = -x;

    if (k > 0) {
        stack<int> ans;
        while (x) {
            ans.push(x % k);
            x /= k;
        }
        if (eumsu) cout << '-';
        while (!ans.empty()) {
            cout << ans.top();
            ans.pop();
        }
        cout << '\n';
        return 0;
    }

    k = -k;

    stack<int> ans;
    ans.push(x % k);
    x /= k;
    while (x) {
        int ab = eumsu ? (-x) % (k * k) : x % (k * k);
        int a = ab / k;
        int b = ab % k;
        cout << x << ' ' << a << ' ' << b << '\n';
        if (x < k * k && eumsu) { // Case: Nigger
            if (a == 0) ans.push(b);
            else ans.push(k * k + k * (k - a) + b);
        }
        
        x /= k * k;

        if (b == 0) ans.push(a * k);
        else {
            if (a == k-1) {
                x += 1;
                ans.push(k - b);
            }
            else ans.push(k * (a + 1) + k - b);
        }
    }

    while (!ans.empty()) {
        if (ans.top() != 0) cout << ans.top() / k;
        cout << ans.top() % k;
        ans.pop();
    }
    cout << '\n';
}