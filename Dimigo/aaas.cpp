#include<bits/stdc++.h>

using namespace std;

using LL = long long;

set<long long> nums;

int main() {

    for (long long k = 2; k <= 1000000; ++k) {
        long long val = 1 + k;
        long long p = k*k;
        for (int cnt = 3; cnt <= 63; ++cnt) {
            val += p;
            if (val > 1e18) break;
            nums.insert(val);
            if (p > (long long)(1e18) / k) break;
            p *= k;
        }
    }

    cout << nums.size() << '\n';

    int _ = 0, __ = 1;
    cin >> __;

    for (int _ = 0; _ < __; ++_) {
        long long n;
        cin >> n;
        if (n < 3)
        {
            cout << "NO" << endl;
            continue;
        }
        long long d = 4*n - 3;
        long long sq = sqrt(d);
        long long sqd = -1;
        for (long long i = max(0ll, sq - 5); i <= sq + 5; ++i) {
            if (i*i == d)
            {
                sqd = i;
                break;
            }
        }
        if (sqd != -1 && (sqd - 1) % 2 == 0 && (sqd - 1) / 2 > 1)
        {
            cout << "YES" << endl;
            continue;
        }

        if (nums.count(n)) cout << "YES" << endl;
        else cout << "NO" << endl;

    }


    return 0;
}