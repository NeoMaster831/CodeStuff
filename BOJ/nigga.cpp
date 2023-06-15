#include <bits/stdc++.h>
   
using namespace std;
#define int long long

int N;

signed main()
{
	cin >> N;
	vector<int> unsorted, sorted;

	for (int i = 0; i < N; i++) {
		int inp; cin >> inp;
		unsorted.push_back(inp);
		sorted.push_back(inp);
	}

	sort(sorted.begin(), sorted.end());

    int ans = 0, mini = 9876543212345678;
	for (int i = 0; i < N; i++) if (sorted[i] != unsorted[i] && mini > sorted[i]) mini = sorted[i];
	for (int i = 0; i < N; i++) if (sorted[i] != unsorted[i] && mini != sorted[i]) ans += sorted[i] + mini;

	cout << ans << '\n';
}