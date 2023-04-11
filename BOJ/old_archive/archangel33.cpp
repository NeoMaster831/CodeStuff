#include <bits/stdc++.h>

using namespace std;

int N, cows[100001], contour, lb[200011];
queue<int> q;
int tree[400004], arr[100001];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        init(node * 2, start, (start + end) / 2);
        init(node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

int query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int l = query(node * 2, start, (start + end) / 2, left, right);
    int r = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return l + r;
}

void update_plus1(int node, int start, int end, int idx) {
    if (idx < start || idx > end) return;
    tree[node] = tree[node] + 1;
    if (start != end) {
        update_plus1(node * 2, start, (start + end) / 2, idx);
        update_plus1(node * 2 + 1, (start + end) / 2 + 1, end, idx);
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> cows[i];
    }

    contour = N - 1;
    for (int i = N; i >= 2; i--) {
        if (cows[i - 1] < cows[i]) contour--;
        else break;
    }
    cout << contour << '\n';

    for (int i = 1; i <= contour; i++) q.push(cows[i]);
    for (int i = contour + 1; i <= N; i++) {
        arr[cows[i]] = 1;
    }

    init(1, 1, N);
    // BEWARE: SEGTREE IS 1~N
    // BEWARE: SEGTREE IS 1~N
    // BEWARE: SEGTREE IS 1~N
    // BEWARE: SEGTREE IS 1~N
    // BEWARE: SEGTREE IS 1~N

    vector<int> ans;
    while (contour--) {
        int fir = q.front(); q.pop();
        
        update_plus1(1, 1, N, fir);
        int K = 0;
        if (fir - 1) K = query(1, 1, N, 1, fir - 1);
        
        ans.push_back(K + contour);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
}