#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s, t, u;
    cin >> s;
    cin >> t;
    cin >> u;

    int next;
    if (u != "FizzBuzz" && u != "Fizz" && u != "Buzz") {
        next = atoi(u.c_str()) + 1;
    } else if (t != "FizzBuzz" && t != "Fizz" && t != "Buzz") {
        next = atoi(t.c_str()) + 2;
    } else {
        next = atoi(s.c_str()) + 3;
    }
    if (next % 3 == 0 && next % 5 == 0) cout << "FizzBuzz" << '\n';
    else if (next % 3 == 0) cout << "Fizz" << '\n';
    else if (next % 5 == 0) cout << "Buzz" << '\n';
    else cout << next << '\n';
}