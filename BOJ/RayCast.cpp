#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main()
{
	int N;
    cin >> N;
    
	vector<int> u, s;
	for(int i = 0; i < N; i++)
	{
		int inp; cin >> inp;
		u.push_back(inp);
		s.push_back(inp);

	}
    int mini = 99999992134712743;
    int ans = 0;
	sort(s.begin(), s.end());
	for(int i = 0; i < N; i++)
	{
		if(s[i] != u[i])
			if(mini > s[i]) mini = s[i];
	}
	for(int i = 0; i < N; i++) //
	{
		if(s[i] != u[i] && mini != s[i])
			ans += s[i] + mini;
	}
	cout << ans << endl;
}