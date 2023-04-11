#include <bits/stdc++.h>

using namespace std;

int N;

int main() {

    cin >> N;

    pair<int, int> maxi = { -1, 0 };
    for (int i = 1; i <= N; i++) {

        int tmp = i, cnt = 0;
        while (tmp % 2 == 0) {
            tmp /= 2;
            cnt++;
        }

        maxi = max(maxi, {cnt, i});
    }

    cout << maxi.second << '\n';
}