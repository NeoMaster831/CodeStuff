#include <bits/stdc++.h>

using namespace std;
#define pp pair<int, int>
#define f_ first
#define s_ second
#define INF 987654321

int N, Q, U, V;
int K[100001];
pair<int, pp> tree[400004];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = { K[start], { K[start], K[start] } };
    }
    else {
        int left = node * 2, right = node * 2 + 1;
        init(left, start, (start + end) / 2);
        init(right, (start + end) / 2 + 1, end);

        tree[node].f_ = max(tree[right].f_, tree[right].s_.s_ + tree[left].f_);
        tree[node].s_.f_ = max({tree[left].s_.f_, tree[right].s_.f_, tree[left].f_});
        tree[node].s_.s_ = tree[left].s_.s_ + tree[right].s_.s_;

    }
}

void update(int node, int start, int end, int idx, int val) {
    if (idx < start || idx > end) return;
    if (start == end) {
        tree[node] = { val, {val, val}};
        return;
    }

    int left = node * 2, right = node * 2 + 1;
    update(left, start, (start + end) / 2, idx, val);
    update(right, (start + end) / 2 + 1, end, idx, val);

    tree[node].f_ = max(tree[right].f_, tree[right].s_.s_ + tree[left].f_);
    tree[node].s_.f_ = max({tree[left].s_.f_, tree[right].s_.f_, tree[left].f_});
    tree[node].s_.s_ = tree[left].s_.s_ + tree[right].s_.s_;
}

pair<int, pp> query(int node, int start, int end, int left, int right, int t) {
    if (left > end || right < start) {
        return { -INF, { -INF, 0 }}; // return invalid value.
    } if (left <= start && end <= right) {
        auto k = tree[node];
        k.first = t - k.first;
        k.second.first = t - k.second.first;
        k.second.second = t - k.second.second;
        cout << k.first <<' ' << k.second.first <<' ' << k.second.second << '\n';
        return k;
    }

    pair<int, pp> l = query(node * 2, start, (start + end) / 2, left, right, t);
    pair<int, pp> r = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right, t);
    pair<int, pp> toret;

    toret.f_ = max(r.f_, r.s_.s_ + l.f_);
    toret.s_.f_ = max({l.s_.f_, r.s_.f_, l.f_});
    toret.s_.s_ = l.s_.s_ + r.s_.s_;

    return toret;
}

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> K[i];
    }

    init(1, 1, N);

    while (Q--) {
        int from, to; cin >> from >> to;
        cout << query(1, 1, N, from, to, 7).s_.f_ << '\n';
    }
}