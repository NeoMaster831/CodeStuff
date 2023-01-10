#include <bits/stdc++.h>

using namespace std;
#define pp pair<int, int>
#define f_ first
#define s_ second
#define INF 987654321

int N, Q, U, V;
int K[100001];
pair<pp, pp> tree[400004];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = { {K[start], K[start]}, { K[start], K[start] } };
    }
    else {
        
        int left = node * 2, right = node * 2 + 1;
        init(left, start, (start + end) / 2);
        init(right, (start + end) / 2 + 1, end);

        tree[node].f_.f_ = max(tree[left].f_.f_, tree[left].s_.s_ + tree[right].f_.f_);
        tree[node].f_.s_ = max(tree[right].f_.s_, tree[right].s_.s_ + tree[left].f_.s_);
        tree[node].s_.f_ = max({tree[left].s_.f_, tree[right].s_.f_, tree[left].f_.s_ + tree[right].f_.f_});
        tree[node].s_.s_ = tree[left].s_.s_ + tree[right].s_.s_;

    }
}

void update(int node, int start, int end, int idx, int val) {
    if (idx < start || idx > end) return;
    if (start == end) {
        tree[node] = { {val, val}, {val, val}};
        return;
    }

    int left = node * 2, right = node * 2 + 1;
    update(left, start, (start + end) / 2, idx, val);
    update(right, (start + end) / 2 + 1, end, idx, val);

    tree[node].f_.f_ = max(tree[left].f_.f_, tree[left].s_.s_ + tree[right].f_.f_);
    tree[node].f_.s_ = max(tree[right].f_.s_, tree[right].s_.s_ + tree[left].f_.s_);
    tree[node].s_.f_ = max({tree[left].s_.f_, tree[right].s_.f_, tree[left].f_.s_ + tree[right].f_.f_});
    tree[node].s_.s_ = tree[left].s_.s_ + tree[right].s_.s_;
}

pair<pp, pp> query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return { { -INF, -INF }, { -INF, 0 }}; // return invalid value.
    } if (left <= start && end <= right) {
        return tree[node];
    }

    pair<pp, pp> l = query(node * 2, start, (start + end) / 2, left, right);
    pair<pp, pp> r = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    pair<pp, pp> toret;

    toret.f_.f_ = max(l.f_.f_, l.s_.s_ + r.f_.f_);
    toret.f_.s_ = max(r.f_.s_, r.s_.s_ + l.f_.s_);
    toret.s_.f_ = max({l.s_.f_, r.s_.f_, l.f_.s_ + r.f_.f_});
    toret.s_.s_ = l.s_.s_ + r.s_.s_;

    return toret;
}

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> Q >> U >> V;
    for (int i = 1; i <= N; i++) {
        cin >> K[i];
        K[i] = K[i] * U + V;
    }

    init(1, 1, N);

    while (Q--) {
        int C; cin >> C;
        if (C == 0) {
            int from, to; cin >> from >> to;
            cout << query(1, 1, N, from, to).s_.f_ - V << '\n';
        } else {
            int what, val; cin >> what >> val;
            update(1, 1, N, what, val * U + V);
        }
    }
}