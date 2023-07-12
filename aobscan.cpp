#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <set>

using namespace std;

typedef complex<double> Complex;
typedef vector<Complex> Polynomial;

void FFT(Polynomial& poly, bool inverse = false) {
    const int n = poly.size();
    if (n <= 1)
        return;

    Polynomial even(n / 2), odd(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        even[i] = poly[i * 2];
        odd[i] = poly[i * 2 + 1];
    }

    FFT(even, inverse);
    FFT(odd, inverse);

    const double angle = 2 * M_PI / n * (inverse ? -1 : 1);
    Complex w(1), wn(cos(angle), sin(angle));

    for (int i = 0; i < n / 2; ++i) {
        Complex temp = w * odd[i];
        poly[i] = even[i] + temp;
        poly[i + n / 2] = even[i] - temp;
        w *= wn;
    }

    if (inverse) {
        for (int i = 0; i < n; ++i)
            poly[i] /= 2;
    }
}

Polynomial multiplyPolynomials(const Polynomial& T, const Polynomial& S) {
    int n = 1;
    while (n < T.size() + S.size())
        n <<= 1;

    Polynomial a(n), b(n), c(n);

    for (int i = 0; i < T.size(); ++i)
        a[i] = T[i];
    for (int i = 0; i < S.size(); ++i)
        b[i] = S[i];

    FFT(a);
    FFT(b);

    for (int i = 0; i < n; ++i)
        c[i] = a[i] * b[i];

    FFT(c, true);

    return c;
}

#define BYTE unsigned char

int main() {
	
    vector<BYTE> to_find = { 0, 1 };
    string mask = "?x";
    vector<BYTE> targ = { 1, 2, 1, 1, 3, 1 ,3, 1 ,3 ,1 ,3 ,1 ,3 ,11 ,1  ,2, 3};

	for (int i = 0; i < to_find.size() / 2; i++) {
        swap(mask[i], mask[mask.size() - 1 - i]);
		swap(to_find[i], to_find[to_find.size() - 1 - i]);
	}

    set<int> found;
    for (int j = 0; j < targ.size(); j += to_find.size()) {

        vector<BYTE> target;
        for (int i = j; i < min(j + 2 * to_find.size(), targ.size()); i++) {
            target.push_back(targ[i]);
        }

        Polynomial T[4], S[4];
        for (int i = 0; i < to_find.size(); i++) {
            if (mask[i] == '?') T[1].push_back(0);
            else T[1].push_back(to_find[i] + 1);
        }

        for (int i = 0; i < target.size(); i++) {
            S[1].push_back(target[i] + 1);
        }

        for (int i = 0; i < S[1].size(); i++) {
            S[2].push_back((int)S[1][i].real()*(int)S[1][i].real());
            S[3].push_back((int)S[2][i].real()*(int)S[1][i].real());
        }
        
        for (int i = 0; i < T[1].size(); i++) {
            T[2].push_back((int)T[1][i].real()*(int)T[1][i].real());
            T[3].push_back((int)T[2][i].real()*(int)T[1][i].real());
        }

        Polynomial result[4];
        for (int k = 1; k <= 3; k++) {
            result[k] = multiplyPolynomials(T[4 - k], S[k]);
        }

        Polynomial check;
        for (int k = 0; k < result[1].size(); k++) {
            check.push_back((int)result[1][k].real() + -2 * (int)result[2][k].real() + (int)result[3][k].real());
        }
        for (int i = to_find.size() - 1; i < target.size(); i++) {
            if (abs((int)check[i].real() < 3.96974)) {
                found.insert(j + i - to_find.size() + 1);
            }
        }
    }

    for (auto iter = found.begin(); iter != found.end(); iter++) {
        cout << "found @ " << *iter << '\n';
    }

    return 0;
}