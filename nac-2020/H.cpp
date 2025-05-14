#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;

const int maxN = 5e3 + 5;
const int mod1 = 983736953;
const int mod2 = 998244353;
const int base = 5;

int binpow(int a, int b, int mod) {
    if (!b) return 1;
    int x = binpow(a, b / 2, mod);
    x = (x * x) % mod;
    if (b & 1) return (x * a) % mod;
    return x;
}

int bindiv(int a, int b, int mod) {
    return a * binpow(b, mod - 2, mod) % mod;
}

int add(int a, int b, int mod) {
    if (a + b > mod) return a + b - mod;
    return a + b;
}

int sub(int a, int b, int mod) {
    if (a < b) return a + mod - b;
    return a - b;
}

int mul(int a, int b, int mod) {
    return a * b % mod;
}

int n;
ii hash_value[maxN];
map<ii, vector<int>> M;

string s1;
string s2;
string s3, g3;

ii get_hash(string s) {
    int val1 = 0;
    int val2 = 0;
    for (int i = 0 ; i < n ; i++) {
        val1 = add(mul(val1, base, mod1), (s[i] - 'A' + 1), mod1);
        val2 = add(mul(val2, base, mod2), (s[i] - 'A' + 1), mod2);
    }
    return ii(val1, val2);
}

void proc_s3() {
    hash_value[0] = get_hash(s3);
    M[hash_value[0]].push_back(0);
    int val1 = hash_value[0].first;
    int val2 = hash_value[0].second;
    for (int i = 1 ; i < n ; i++) {
        int t = (s3[n - i] - 'A' + 1);
        val1 = sub(val1, t, mod1);
        val1 = bindiv(val1, base, mod1);
        val1 = add(val1, mul(t, binpow(base, n - 1, mod1), mod1), mod1);
        val2 = sub(val2, t, mod2);
        val2 = bindiv(val2, base, mod2);
        val2 = add(val2, mul(t, binpow(base, n - 1, mod2), mod2), mod2);
        hash_value[i] = ii(val1, val2);
        M[ii(val1, val2)].push_back(i);
    }
}

int get_min(int r1, int r2) {
    if (r1 > r2) swap(r1, r2);
    int l1 = n - r1;
    int l2 = n - r2;
    int res = min(l1, r1) + min(l2, r2);
    res = min(res, min(n - r1, r1) + min(r2 - r1, n - r2 + r1));
    res = min(res, min(n - r2, r2) + min(n + r1 - r2, r2 - r1));
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> s1 >> s2 >> s3;
    n = s1.length();
    int ans = mod1;
    proc_s3();
    for (int i = 0 ; i < n ; i++) {
        // rotate s2 i steps to the right
        g3 = "";
        for (int i1 = 0 ; i1 < n ; i1++) {
            int i2 = i1 - i;
            if (i2 < 0) i2 += n;
            if (s1[i1] == s2[i2]) break;
            else g3 += (3 - (s1[i1] - 'A') - (s2[i2] - 'A') + 'A');
        }
        if (g3.length() != n) continue;
        ii g3_hash_val = get_hash(g3);
        if (M.count(g3_hash_val) == 0) continue;
        for (int u: M[g3_hash_val]) {
            ans = min(ans, get_min(i, u));
        }
    }
    if (ans == mod1) cout << -1;
    else cout << ans;
}