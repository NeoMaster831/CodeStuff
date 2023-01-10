#include <bits/stdc++.h>

using namespace std;

int N, a[200001], cnt[200001], p[200001], q[200001];
pair<int, int> b[200001];
bool x[200001][2];

void solve() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= N; i++) {
        cnt[i] = 0; p[i] = 0; q[i] = 0;
        b[i] = {0, 0};
        x[i][0] = false; x[i][1] = false;
    }

    for (int i = 1; i <= N; i++) {
        int v = a[i]; cnt[v]++;
        b[i] = {a[i], i};
    }
    for (int i = 1; i <= N; i++) {
        if (cnt[i] >= 3 || cnt[1] >= 2) {
            cout << "nO" << '\n';
            return;
        }
    }

    sort(b + 1, b + N + 1);

    int cant = cnt[1] + 1;
    for (int i = 1; i <= N; i++) {
        if (b[i].first != 1 && b[i].first <= cant) { cout << "No" << '\n'; return; }
        if (i != N && b[i].first == b[i + 1].first) { cant += 2; i++; }
    }

    int minidx[2] = { 1, 1 }; int last = 0;
    for (int i = 1; i <= N; i++) {

        if (b[i].first == 1) { // Case 1. a[i] = 1
            int aidx = b[i].second;
            p[aidx] = 1; q[aidx] = 1;
            minidx[0]++; minidx[1]++;
        }
        else {
            int aval = b[i].first, aidx = b[i].second;

            if (aval == last) { // Case 2
                q[aidx] = aval; x[aval][1] = true;
                p[aidx] = minidx[0]++;
            }
            else {
                p[aidx] = aval; x[aval][0] = true;
                q[aidx] = minidx[1]++;
            }
        }

        while (x[minidx[0]][0]) minidx[0]++;
        while (x[minidx[1]][1]) minidx[1]++;

        last = b[i].first;
    }

    cout << "yEs" << '\n';
    for (int i = 1; i <= N; i++) cout << p[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= N; i++) cout << q[i] << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) solve();
}