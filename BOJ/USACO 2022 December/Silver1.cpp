#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
#define int long long
#define ppi pair< pair<int, int>, int>

int N, hays[200011], avg;
vector<int> tree[200011];
bool chk[200011];
stack<ppi> m1nus; queue<ppi> p1us;

int dfs(int node, int last) { // Return: demand

    // Leaf
    if (tree[node].size() == 1 && last != -1) {
        return hays[node] - avg;
    }
    chk[node] = true;

    vector<pair<int, int> > changes;
    int dsum = 0;
    for (int i = 0; i < tree[node].size(); i++) {

        int nxt = tree[node][i];
        if (chk[nxt] || nxt == last) continue;
        int demand = dfs(nxt, node);
        dsum += demand;

        if (demand) {
            changes.push_back({ nxt, demand });
        }

    }
    
    dsum += hays[node] - avg;

    vector<pair<pair<int, int>, int> > preans;

    if (dsum < 0) {
        for (int i = 0; i < changes.size(); i++) {
            if (changes[i].second > 0) continue;
            preans.push_back({ { node, changes[i].first }, -changes[i].second });
        }
        for (int i = 0; i < changes.size(); i++) {
            if (changes[i].second < 0) continue;
            preans.push_back({ { changes[i].first, node }, changes[i].second });
        }
        for (int i = 0; i < preans.size(); i++) m1nus.push(preans[i]);
    } else {
        for (int i = 0; i < changes.size(); i++) {
            if (changes[i].second < 0) continue;
            preans.push_back({ { changes[i].first, node }, changes[i].second });
        }
        for (int i = 0; i < changes.size(); i++) {
            if (changes[i].second > 0) continue;
            preans.push_back({ { node, changes[i].first }, -changes[i].second });
        }
        for (int i = 0; i < preans.size(); i++) p1us.push(preans[i]);
    }

    return dsum;
}

signed main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> hays[i];
    for (int i = 1; i < N; i++) {
        int from, to; cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    int sum = 0;
    for (int i = 1; i <= N; i++) sum += hays[i];
    avg = sum / N;

    int demand = dfs(1, -1);
    cout << p1us.size() + m1nus.size() << '\n';
    while (!p1us.empty()) { cout << p1us.front().first.first << ' ' << p1us.front().first.second << ' ' << p1us.front().second << '\n'; p1us.pop(); }
    while (!m1nus.empty()) { cout << m1nus.top().first.first << ' ' << m1nus.top().first.second << ' ' << m1nus.top().second << '\n'; m1nus.pop(); }
}