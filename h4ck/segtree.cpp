#include <bits/stdc++.h>

using namespace std;
#define int long long

typedef struct Node {
    int add;
    int _xor;
} Node;

Node tree[100001];
int arr[100001];

Node init(int node, int st, int en) {
    if (st == en) {
        tree[node].add = arr[st];
        tree[node]._xor = arr[st];
    }
    else {
        int mid = (st + en) / 2;
        Node l = init(node * 2, st, mid);
        Node r = init(node * 2 + 1, mid + 1, en);
        tree[node].add = l.add + r.add;
        tree[node]._xor = l._xor ^ r._xor;
    }
    return tree[node];
}

signed main() {
    for (int i = 0; i < 256; i++) {
        arr[i] = i;
    }
    init(1, 0, 255);
    cout << arr[1] << '\n';
    cout << tree[1].add << ' ' << tree[1]._xor << '\n';
} 