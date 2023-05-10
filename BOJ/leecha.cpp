#include <iostream>

using namespace std;

int main() {
    int a, b; cin >> a >> b;
    
    bool minus = a < 0;
    if (minus) a = -a;

    bool found = false;

    pair<int, int> ans;
    for (int i = 1; i * i <= b; i++) {
        if (b % i != 0) continue;
        int fir = i;
        int sec = b / i;
        if (fir + sec == a) {
            found = true;
            ans = { fir, sec };
        }
    }

    if (!found) { cout << "인수분해가 불가능합니다." << '\n'; return 0; }
    if (minus) { cout << "(x - " << ans.first << ")(x - " << ans.second << ")\n"; }
    if (!minus) { cout << "(x + " << ans.first << ")(x + " << ans.second << ")\n"; }
}