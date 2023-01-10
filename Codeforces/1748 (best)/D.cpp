#include <bits/stdc++.h>

using namespace std;

int N, X;
int A[500001], when[500001];

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int mini = 500003;
    for (int i = 1; i <= N; i++) {
        when[A[i] + 1]++;
        mini = min(mini, A[i] + 1);
    }


    int ptr = mini, vanolim = 0;
    bool cant = false;
    while (ptr <= X) {
        int val = when[ptr];
        if ((val + vanolim) % ptr != 0) {cant = true; break;}
        else {
            vanolim = (val + vanolim) / ptr;
        }
        ptr++;
    }

    if (cant) cout << "No" << '\n';
    else cout << "Yes" << '\n';
}