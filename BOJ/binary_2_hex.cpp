#include <bits/stdc++.h>

using namespace std;

const char* HEX = "0123456789ABCDEF";

int main() {

    string inp; cin >> inp;
    reverse(inp.begin(), inp.end());

    stack<char> buf;
    int x = 1, j = 0;
    for (int i = 0; i < inp.size(); i++) {
        int h = inp[i] - 48;
        j += h * x;
        if (x == 8) {
            buf.push(HEX[j]);
            j = 0;
            x = 1;
        }
        else if (i == inp.size() - 1) {
            buf.push(HEX[j]);
            break;
        } else x *= 2;
    }

    while (!buf.empty()) {
        cout << buf.top(); buf.pop();
    }
}