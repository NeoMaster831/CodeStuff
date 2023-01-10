#include <bits/stdc++.h>

using namespace std;

int A, B;

int main() {
    cin >> A >> B;

    int ans = 1;
    for (int i = 1; i <= B; i++) {
        ans = ans * A;
    }

    cout << ans << '\n';
}