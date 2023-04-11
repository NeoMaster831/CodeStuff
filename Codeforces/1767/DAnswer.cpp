#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int k = count(s.begin(), s.end(), '1');
  for (int x = 1 << k; x <= (1 << n) - (1 << (n - k)) + 1; ++x)
    cout << x << ' ';
}