#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

struct Line {
    mutable ld k, m, p;
    bool operator< (const Line& o) const { return k < o.k; }
    bool operator< (ld x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    static constexpr ld inf = 1e100;
    ld div(ld a, ld b) {
        return a / b;
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ld k, ld m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
    }
    ld query(ld x) {
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
} lc;

const int maxN = 5e5 + 5;
ld dp[maxN];
ld p[maxN];
int n;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
	cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> p[i];
    }
	dp[n] = 0;
	for(int k = n - 1 ; k >= 0 ; k--){
		ld b = p[k] * (k + 1 + dp[k+1]);
		ld m = -p[k];
		lc.add(m, b);
		dp[k] = lc.query(1.0 * k);
	}
	cout << fixed << setprecision(12) << dp[0] << endl;
}