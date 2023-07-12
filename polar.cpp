#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T> tuple<T, T, T> ext_gcd(T a, T b) {
    if (!a) return {b, 0, 1};
    auto [g, x, y] = ext_gcd(b%a, a);
    return {g, y - b/a*x, x};
}

template<typename T = ll> struct crt {
        T a, m;

        crt() : a(0), m(1) {}
        crt(T a_, T m_) : a(a_), m(m_) {}
        crt operator * (crt C) {
                auto [g, x, y] = ext_gcd(m, C.m);
                if ((a - C.a) % g) a = -1;
                if (a == -1 or C.a == -1) return crt(-1, 0);
                T lcm = m/g*C.m;
                T ans = a + (x*(C.a-a)/g % (C.m/g))*m;
                return crt((ans % lcm + lcm) % lcm, lcm);
        }
};

template<int p> struct mod_int {
        ll pow(ll b, ll e) {
                if (e == 0) return 1;
                ll r = pow(b*b%p, e/2);
                if (e%2 == 1) r = (r*b)%p;
                return r;
        }
        ll inv(ll b) { return pow(b, p-2); }

        using m = mod_int;
        int v;
        mod_int() : v(0) {}
        mod_int(ll v_) {
                v = v_;
                if (v >= p or v <= -p) v %= p;
                if (v < 0) v += p;
        }
        m& operator+=(const m &a) {
                v += a.v;
                if (v >= p) v -= p;
                return *this;
        }
        m& operator-=(const m &a) {
                v -= a.v;
                if (v < 0) v += p;
                return *this;
        }
        m& operator*=(const m &a) {
                v = v * ll(a.v) % p;

                return *this;
        }
        m& operator/=(const m &a) {
                v = v* inv(a.v) % p;
                return *this;
        }
        m operator-(){ return m(-v); }
        m& operator^=(ll e) {
                if (e < 0){
                        v = inv(v);
                        e = -e;
                }
                v = pow(v, e%(p-1));
                return *this;
        }
        bool operator==(const m &a) { return v == a.v; }
        bool operator!=(const m &a) { return v != a.v; }

        friend istream &operator>>(istream &in, m& a) {
                ll val; in >> val;
                a = m(val);
                return in;
        }
        friend ostream &operator<<(ostream &out, m a) {
                return out << a.v;
        }
        friend m operator+(m a, m b) { return a+=b; }
        friend m operator-(m a, m b) { return a-=b; }
        friend m operator*(m a, m b) { return a*=b; }
        friend m operator/(m a, m b) { return a/=b; }
        friend m operator^(m a, ll e) { return a^=e; }
};

typedef mod_int<(int)1e9+7> mint;

// Para NTT
// 91cd08
template<int p>
void get_roots(bool f, int n, vector<mod_int<p>>& roots) {
        mod_int<p> r;
        int ord;
        if (p == 998244353) {
                r = 102292;
                ord = (1 << 23);
        } else if (p == 754974721) {
                r = 739831874;
                ord = (1 << 24);
        } else if (p == 167772161) {
                r = 243;
                ord = (1 << 25);
        } else assert(false);

        if (f) r = r^(p - 1 -ord/n);
        else r = r^(ord/n);
        roots[0] = 1;
        for (int i = 1; i < n/2; i++) roots[i] = roots[i-1]*r;
}

// d5c432
template<typename T> void fft(vector<T> &a, bool f, int N, vector<int> &rev) {
        for (int i = 0; i < N; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
        int l, r, m;
        vector<T> roots(N);
        for (int n = 2; n <= N; n *= 2) {
                get_roots(f, n, roots);

                for (int pos = 0; pos < N; pos += n) {
                        l = pos+0, r = pos+n/2, m = 0;
                        while (m < n/2) {
                                auto t = roots[m]*a[r];
                                a[r] = a[l] - t;
                                a[l] = a[l] + t;
                                l++; r++; m++;
                        }
                }
        }
        if (f) {
                auto invN = T(1)/T(N);
                for (int i = 0; i < N; i++) a[i] = a[i]*invN;
        }
}
template<typename T> vector<T> convolution(vector<T> &a, vector<T> &b) {
        vector<T> l(a.begin(), a.end());
        vector<T> r(b.begin(), b.end());
        int ln = l.size(), rn = r.size();
        int N = ln+rn-1;
        int n = 1, log_n = 0;
        while (n <= N) { n <<= 1; log_n++; }
        vector<int> rev(n);
        for (int i = 0; i < n; ++i) {
                rev[i] = 0;
                for (int j = 0; j < log_n; ++j)
                        if (i & (1<<j)) rev[i] |= 1 << (log_n-1-j);
        }
        assert(N <= n);
        l.resize(n);
        r.resize(n);
        fft(l, false, n, rev);
        fft(r, false, n, rev);
        for (int i = 0; i < n; i++) l[i] *= r[i];
        fft(l, true, n, rev);
        l.resize(N);
        return l;
}

// NTT
// 3bf256
template<int p, typename T> vector<mod_int<p>> ntt(vector<T>& a, vector<T>& b) {
        vector<mod_int<p>> A(a.begin(), a.end()), B(b.begin(), b.end());
        return convolution(A, B);
}

template<typename T, int mods>
vector<T> int_convolution(vector<int>& a, vector<int>& b) {
        static const int M1 = 998244353, M2 = 754974721, M3 = 167772161;

        auto c1 = ntt<M1>(a, b);
        auto c2 = (mods >= 2 ? ntt<M2>(a, b) : vector<mod_int<M2>>());
        auto c3 = (mods >= 3 ? ntt<M3>(a, b) : vector<mod_int<M3>>());

        vector<T> ans;
        for (int i = 0; i < c1.size(); i++) {
                crt<T> at(c1[i].v, M1);
                if (mods >= 2) at = at * crt<T>(c2[i].v, M2);
                if (mods >= 3) at = at * crt<T>(c3[i].v, M3);
                ans.push_back(at.a);
                if (at.a > at.m/2) ans.back() -= at.m;
        }
        return ans;
}

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
        uniform_int_distribution<int> uid(l, r);
        return uid(rng);
}

template<int MOD> struct str_hash { // 116fcb
        static int P;
        vector<ll> h, p;
        str_hash(string s) : h(s.size()), p(s.size()) {
                p[0] = 1, h[0] = s[0];
                for (int i = 1; i < s.size(); i++)
                        p[i] = p[i - 1]*P%MOD, h[i] = (h[i - 1]*P + s[i])%MOD;
        }
        ll operator()(int l, int r) { // retorna hash s[l...r]
                ll hash = h[r] - (l ? h[l - 1]*p[r - l + 1]%MOD : 0);
                return hash < 0 ? hash + MOD : hash;
        }
};
template<int MOD> int str_hash<MOD>::P = uniform(256, MOD - 1); // l > |sigma|

int main() {
  fast_io;

  int n, m;
  cin >> n >> m;

  string s, t;
  cin >> s >> t;

  vector<int> S(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == '?')
      S[i] = 0;
    else
      S[i] = (s[i] - 'A' + 1);
  }
  reverse(S.begin(), S.end());

  vector<int> T(m);
  for (int i = 0; i < m; i++) {
    if (t[i] == '?')
      T[i] = 0;
    else
      T[i] = (t[i] - 'A' + 1);
  }

  vector<int> S2 = S;
  vector<int> T2 = T;

  vector<int> S3 = S;
  vector<int> T3 = T;

  auto square = [] (vector<int>& v) {
    for (int i = 0; i < v.size(); i++)
      v[i] = v[i] * v[i];
  };

  auto cube = [] (vector<int>& v) {
    for (int i = 0; i < v.size(); i++)
      v[i] = v[i] * v[i] * v[i];
  };

  square(S2); square(T2);
  cube(S3); cube(T3);

  auto S3T = int_convolution<int, 1>(S3, T);
  auto S2T2 = int_convolution<int, 1>(S2, T2);
  auto ST3 = int_convolution<int, 1>(S, T3);

  str_hash<(int) 1e9 + 7> hash(t);
  vector<int> v;

  for (int i = 0; i < m - n + 1; i++) {
    int a = S3T[i + n - 1];
    int b = S2T2[i + n - 1];
    int c = ST3[i + n - 1];
    if (a - 2*b + c == 0) {
      v.push_back(hash(i, i + n - 1));
    }
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  cout << v.size() << endl;

  return 0;
}