#include <bits/stdc++.h>

using namespace std;
#define int long long
#define INF 2365178465178

int N, C[100001], tree[400004];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = C[start];
    } else {
        init(node * 2, start, (start + end) / 2);
        init(node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
}

int query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return INF;
    } if (left <= start && end <= right) {
        return tree[node];
    }

    int l = query(node * 2, start, (start + end) / 2, left, right);
    int r = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return min(l, r);
}

signed main() {
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
    }

    int preans = -1;
    // Pre-process
    for (int i = 1; i <= N; i++) {

        int r = i, cnt = 0;
        if (C[i] == 0) continue;

        while (C[r] == C[i]) {
            cnt++; r++;
        }

        if (cnt >= N - C[i]) {
            preans = C[i];
            break;
        }
        i = r;

    }

    if (preans != -1) { cout << preans << '\n'; return 0; }

    init(1, 1, N);

    int ans = 0;
    for (int i = 1; i <= N - ans; i++) {
        int val = C[i];
        int mq = query(1, 1, N, i, N - C[i]);

        cout << "Min Query (" << i << "): " << mq << '\n';
        if (mq == INF) {
            ans = N - i; break;
        }
        if (mq >= val) {
            ans = max(ans, val);
        }
    }

    cout << ans << '\n';
}