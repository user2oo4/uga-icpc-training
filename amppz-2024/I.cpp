#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
const int maxN = 2002;
const int maxA = 1e6 + 6;

int a[maxN];
int cnt[maxA];
int pick1[maxA];
int pick2[maxA];
int fact[maxN];
int n, k;

int binpow(int a, int b) {
    if (!b) return 1;
    int x = binpow(a, b / 2);
    x = x * x % mod;
    if (b & 1) return x * a % mod;
    return x;
}

int inv(int x) {
    return binpow(x, mod - 2);
}

int C(int n, int k) {
    return fact[n] * inv(fact[k]) % mod * inv(fact[n - k]) % mod;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> k;
    fact[0] = 1;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        fact[i] = fact[i - 1] * i % mod;
    }
    sort(a + 1, a + 1 + n);
    int ans1 = 0;
    for (int i = 1 ; i <= k ; i++) {
        pick1[a[i]]++;
        ans1 -= a[i];
    }
    for (int i = n ; i >= n - k + 1 ; i--) {
        pick2[a[i]]++;
        ans1 += a[i];
    }
    int ans2 = 1;
    for (int i = 1 ; i <= n ; i++) {
        if (a[i] == a[i - 1]) continue;
        ans2 = ans2 * C(cnt[a[i]], pick1[a[i]]) % mod;
        ans2 = ans2 * C(cnt[a[i]] - pick1[a[i]], pick2[a[i]]) % mod;
    }
    if (!ans1) ans2 = ans2 * inv(2) % mod;
    cout << ans1 << " " << ans2;
}