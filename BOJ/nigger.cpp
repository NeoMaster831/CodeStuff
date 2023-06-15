#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
const int MAX = 3011;
const double INF = 0x3f3f3f3f;
const int LNF = 1e16;
const int MOD = 1e9 + 7;
struct Point {
	ll x, y, cost;
};
ll Mx = 1, My = 1, N, a[MAX][MAX], ans = -LNF;
pl tmpX[MAX], tmpY[MAX];
Point p[MAX];
vector<pl> yList[MAX];
struct Node {
	ll lsum, rsum, sum, maxsum;
};
Node tree[1 << 14];
Node merge(Node A, Node B) {
	return {
		max(A.lsum, A.sum + B.lsum),
		max(B.rsum, B.sum + A.rsum),
		A.sum + B.sum,
		max({ A.maxsum,B.maxsum,A.rsum + B.lsum })
	};
}
Node query(int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return { -LNF,-LNF, -LNF,-LNF };
	if (left <= s && e <= right)
		return tree[node];
	int mid = (s + e) / 2;
	return merge(query(node * 2, s, mid, left, right),
		query(node * 2 + 1, mid + 1, e, left, right));
}
void update(int node, int s, int e, int idx, ll val) {
	if (e < idx || idx < s)
		return;
	tree[node].lsum += val;
	tree[node].rsum += val;
	tree[node].sum += val;
	tree[node].maxsum += val;
	if (s != e) {
		int mid = (s + e) / 2;
		update(node * 2, s, mid, idx, val);
		update(node * 2 + 1, mid + 1, e, idx, val);
		tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i].x >> p[i].y >> p[i].cost;
		tmpX[i] = { p[i].x, i };
		tmpY[i] = { p[i].y, i };
	}
	sort(tmpX + 1, tmpX + N + 1);
	sort(tmpY + 1, tmpY + N + 1);
	for (int i = 1; i <= N; i++) {
		if (i != 1 && tmpX[i - 1].first != tmpX[i].first)
			Mx++;
		p[tmpX[i].second].x = Mx;
	}
	for (int i = 1; i <= N; i++) {
		if (i != 1 && tmpY[i - 1].first != tmpY[i].first)
			My++;
		p[tmpY[i].second].y = My;
	}
	for (int i = 1; i <= N; i++) {
		a[p[i].x][p[i].y] = p[i].cost;
		yList[p[i].y].push_back({ p[i].x, p[i].cost });
	}
	for (int k = 1; k <= My; k++) {
		memset(tree, 0, sizeof(tree));
		for (int i = k; i <= My; i++) {
			for (auto j : yList[i]) {
				update(1, 1, N, j.first, j.second);
			}
			ans = max(ans, query(1, 1, N, 1, N).maxsum);
		}
	}
	cout << ans << "\n";
}