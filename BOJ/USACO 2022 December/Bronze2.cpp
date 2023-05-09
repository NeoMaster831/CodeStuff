#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define int long long
#define INF 98765432123456

int N, K;
string fm;

void solve() {
    cin >> N >> K >> fm;

    int g = -INF, h = -INF;
    int ans = 0;

    vector<char> ansp;
    for (int i = 0; i < N; i++) ansp.push_back('.');
    for (int i = 0; i < N; i++) {
        //cout << g << ' ' << h << '\n';
        if (fm[i] == 'G' && g < i) {
            ans++; g = i + 2 * K;
            if (i + K >= N) {
                if (ansp[N - 1] == 'H') ansp[N - 2] = 'G';
                else ansp[N - 1] = 'G';
            }
            else ansp[i + K] = 'G';
        } else if (fm[i] == 'H' && h < i) {
            ans++; h = i + 2 * K;
            if (i + K >= N) {
                if (ansp[N - 1] == 'G') ansp[N - 2] = 'H';
                else ansp[N - 1] = 'H';
            }
            else ansp[i + K] = 'H';
        }
    }

    cout << ans << '\n';
    for (int i = 0; i < N; i++) cout << ansp[i];
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T; while (T--) solve();
}