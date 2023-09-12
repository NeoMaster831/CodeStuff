#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

typedef complex<double> Complex;
typedef vector<Complex> Polynomial;

// 다항식의 곱셈을 위한 FFT 함수
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

// 다항식 곱셈 함수
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

int p[1001][1001], q[1001][1001];
int RP, CP, RQ, CQ;

int main() {

    cin >> RP >> CP;
    for (int i = 1; i <= RP; i++) {
        for (int j = 1; j <= CP; j++) {
            cin >> p[i][j];
        }
    }
    cin >> RQ >> CQ;
    for (int i = 1; i <= RQ; i++) {
        for (int j = 1; j <= CQ; j++) {
            cin >> q[i][j];
        }
    }

    vector<int> to_find;
    vector<int> target;
    if (RP > RQ || CP > CQ) { cout << 0 << '\n'; return 0; }
    for (int i = 1; i <= RP; i++) {
        for (int j = 1; j <= CP; j++) {
            to_find.push_back(p[i][j]);
        }
        if (i == RP) continue;
        for (int j = 1; j <= CQ - CP; j++) {
            to_find.push_back(0);
        }
    }
    for (int i = 1; i <= RQ; i++) for (int j = 1; j <= CQ; j++) target.push_back(q[i][j]);

    vector<int> R;
	for (int i = to_find.size() - 1; i >= 0; i--) {
		R.push_back(to_find[i]);
	}

    Polynomial T[4], S[4];
	for (int i = 0; i < R.size(); i++) {
        T[1].push_back(R[i]);
	}
	for (int i = 0; i < target.size(); i++) {
		S[1].push_back(target[i]);
	}
	for (int i = 0; i < S[1].size(); i++) {
		S[2].push_back((double)S[1][i].real()*(double)S[1][i].real());
		S[3].push_back((double)S[2][i].real()*(double)S[1][i].real());
	}
	for (int i = 0; i < T[1].size(); i++) {
		T[2].push_back((double)T[1][i].real()*(double)T[1][i].real());
		T[3].push_back((double)T[2][i].real()*(double)T[1][i].real());
	}

	Polynomial result[4];
	for (int k = 1; k <= 3; k++) {
		result[k] = multiplyPolynomials(T[4 - k], S[k]);
	}

	Polynomial check;
	for (int k = 0; k < result[1].size(); k++) {
		check.push_back((double)result[1][k].real() + -2 * (double)result[2][k].real() + (double)result[3][k].real());
	}
    vector<pair<int, int> > ans;
	for (int i = to_find.size() - 1; i < target.size(); i++) {
        if ((i - to_find.size() + 1) % CQ > CQ - CP) continue;
		if (abs((double)check[i].real() < 1e-6)) {
            int linear = i - to_find.size() + 2;
            int row = linear / CQ + 1;
            int column = linear % CQ + 1;
            column--;
            if (column <= 0) {
                row -= 1;
                column = CQ;
            }
            ans.push_back({row, column});
		}
	}

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }

    return 0;
}