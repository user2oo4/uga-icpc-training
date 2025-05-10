#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;
const int maxN = 1e5 + 5;

int pw2[maxN];
int p[maxN];
int n, q;

int binpow(int a, int b) {
    if (!b) return 1;
    int x = binpow(a, b / 2);
    x = x * x % mod;
    if (b & 1) return x * a % mod;
    return x;
}

int bindiv(int a, int b) {
    return a * binpow(b, mod - 2) % mod;
}

void init() {
    pw2[0] = 1;
    for (int i = 1 ; i <= n ; i++) {
        pw2[i] = pw2[i - 1] * 2;
        if (pw2[i] >= mod) pw2[i] -= mod;
    }
}

struct FT {
    vector<int> s;
    FT(int n) : s(n) {}
    void update(int pos, int dif) { // a [ pos ] += d i f
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    int query(int pos) { // sum of values in [0 , pos)
        int res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
    int lower_bound(int sum) {// min pos st sum of [0 , pos ] >= sum
    // Returns n if no sum is >= sum, or −1 if empty sum is .
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
                pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> q;
    init();
    for (int i = 1 ; i <= n ; i++) {
        cin >> p[i];
    }

}