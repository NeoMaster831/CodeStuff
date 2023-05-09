#include <iostream>
#include <vector>

using namespace std;

int N;
bool habsung[4000001];

int main() {

    vector<int> primes;
    for (int i = 2; i <= 4000000; i++) {
        if (habsung[i]) continue;
        primes.push_back(i);
        for (int j = i * 2; j <= 4000000; j += i) {
            habsung[j] = true;
        }
    }
    

    for (int i = 0; i < 1000; i++) {
        int x = primes[i];
        int s = 0;
        for (int j = 0; j < i; j++) {
            if (primes[j] + s)
        }
    }
}