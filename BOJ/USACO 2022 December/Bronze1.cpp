#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define int long long

int N, C[100001];

signed main() {

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> C[i];

    sort(C + 1, C + N + 1);

    pair<int, int> maxi = { -1, 1 };
    for (int i = 1; i <= N; i++) {
        maxi = max(maxi, {(N - i + 1) * C[i], -C[i]});
    }

    std::cout << maxi.first << ' ' << -maxi.second << '\n';
}