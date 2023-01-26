#include <bits/stdc++.h>

using namespace std;

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    double A, B;
    cin >> A >> B;

    double f = pow(A / 2.0, 2.0 / 3.0);
    double s = B;
    double t = A * pow(B, 1.0 / 3.0) / pow(A / 2.0, 1.0 / 3.0);
    cout << f - s + t << '\n';
}