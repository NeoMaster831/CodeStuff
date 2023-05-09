#include <iostream>
#include <vector>

using namespace std;

const int base = 1000000000; // 10^9
const int base_digits = 9;

vector<int> to_vector(string str) {
    vector<int> res;
    for (int i = str.size(); i > 0; i -= base_digits) {
        int x = 0;
        for (int j = max(0, i - base_digits); j < i; j++)
            x = x * 10 + (str[j] - '0');
        res.push_back(x);
    }
    return res;
}

void print(vector<int> v) {
    cout << v.back();
    for (int i = v.size() - 2; i >= 0; i--) {
        cout.width(base_digits);
        cout.fill('0');
        cout << v[i];
    }
}

vector<int> operator*(const vector<int>& a, const vector<int>& b) {
    vector<int> res(a.size() + b.size());
    for (int i = 0; i < a.size(); i++)
        for (int j = 0, carry = 0; j < b.size() || carry; j++) {
            long long cur = res[i+j] + (long long) a[i] * (j < b.size() ? b[j] : 0) + carry;
            res[i+j] = cur % base;
            carry = cur / base;
        }
    while (res.size() > 1 && res.back() == 0)
        res.pop_back();
    return res;
}

vector<int> power(const vector<int>& a, int b) {
    if (b == 0) return vector<int>(1,1);
    vector<int> res = power(a, b/2);
    res = res * res;
    if (b % 2 == 1) res = res * a;
    return res;
}

int main() {
    vector<int> res = power(to_vector("2"), 100000);
    print(res);
    return 0;
}