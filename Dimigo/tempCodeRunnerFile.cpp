#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long

int N, L, ans[100001];

vector<int> factorize(int x) {

    vector<int> ans;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            ans.push_back(i);
            ans.push_back(x / i);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
    
}

void solve() {

    cin >> N >> L;
    for (int i = 1; i <= N; i++) ans[i] = 0;

    if (N > L) {
        cout << "Can\'t" << '\n';
        return;
    }

    vector<int> fctr = factorize(L);

    int maxi = 0;
    for (int i = 0; i < fctr.size(); i++) {
        
        int k = fctr[i];
        int origin = 1;
        bool can = true;
        for (int i = 1; i <= N; i++) {
            origin *= k;
            if (origin > L) {
                can = false; break;
            }
        }

        if (!can) continue;
        maxi = max(maxi, k);
    }

    cout << maxi << '\n';
    L /= maxi;

    int digit = 1;
    while (digit <= N) {
        ans[digit] = L % maxi;
        L /= maxi;
        digit++;
    }

    ans[N] += L * maxi;

    for (int i = 1; i <= N; i++) {
        if (ans[i] == 0) {
            ans[i] += maxi * maxi;
            ans[i + 1] -= maxi;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T; while (T--) solve();
}