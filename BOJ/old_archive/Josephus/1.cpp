#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> ans;

//
void josephus(int idx, vector<int> left) {

    ans.push_back(left[idx]);

    if (left.size() == 1) cout << left[idx];
    else cout << left[idx] << ", ";

    left.erase(left.begin() + idx);
    int nxt = (idx - 1) + K;
    if (left.size() == 0) return;
    
    nxt %= left.size();

    josephus(nxt, left);
}

int main() {

    cin >> N >> K;

    vector<int> inpt; for (int i = 1; i <= N; i++) inpt.push_back(i);
    
    cout << "<";
    josephus(K - 1, inpt);
    cout << ">";

}