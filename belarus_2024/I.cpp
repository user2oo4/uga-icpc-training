#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
const int mod = 1e9 + 7;
const int maxN = 1505;

int n, m;
int p[maxN][maxN];
int pf[maxN][maxN]; // prefix of p[i, j]
int pf_i[maxN][maxN]; // prefix of p[i, j] * i
int pf_j[maxN][maxN]; // prefix of p[i, j] * j
int pf_ij[maxN][maxN]; // prefix of p[i, j] * i * j

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

int sum(int arr[][maxN], int i1, int j1, int i2, int j2) {
    if (i2 < i1 || j2 < j1) return 0;
    int res = arr[i2][j2] - arr[i2][j1 - 1] - arr[i1 - 1][j2] + arr[i1 - 1][j1 - 1];
    res %= mod;
    if (res < 0) res += mod;
    return res;
}

int area(int i, int j) {
    int area = 0;
    // calculate the expected area when the the first square is (i, j)
    // i2 < i, j2 < j
    area = i * j * sum(pf, 1, 1, i - 1, j - 1) 
            + sum(pf_ij, 1, 1, i - 1, j - 1)
            - j * sum(pf_i, 1, 1, i - 1, j - 1)
            - i * sum(pf_j, 1, 1, i - 1, j - 1);
    area %= mod;
    if (area < 0) area += mod;
    // cout << "area = " << area << endl;
    // i2 > i, j2 < j
    area += (-i * j * sum(pf, i + 1, 1, n, j - 1) 
            - sum(pf_ij, i + 1, 1, n, j - 1)
            + j * sum(pf_i,i + 1, 1, n, j - 1)
            + i * sum(pf_j, i + 1, 1, n, j - 1));
    area %= mod;
    if (area < 0) area += mod;
    // cout << "area = " << area << endl;
    // i2 < i, j2 > j
    area += (-i * j * sum(pf, 1, j + 1, i - 1, m) 
            - sum(pf_ij, 1, j + 1, i - 1, m)
            + j * sum(pf_i,1, j + 1, i - 1, m)
            + i * sum(pf_j, 1, j + 1, i - 1, m));
    area %= mod;
    if (area < 0) area += mod;
    // cout << "area = " << area << endl;
    // i2 > i, j2 > j
    area += (i * j * sum(pf, i + 1, j + 1, n, m) 
            + sum(pf_ij, i + 1, j + 1, n, m)
            - j * sum(pf_i, i + 1, j + 1, n, m)
            - i * sum(pf_j, i + 1, j + 1, n, m));
    area %= mod;
    if (area < 0) area += mod;
    // cout << "area = " << area << endl;
    // i2 = i, j2 < j
    int mul = bindiv(1, 3);
    area += (j * sum(pf, i, 1, i, j - 1) - sum(pf_j, i, 1, i, j - 1)) * mul;
    area %= mod;
    if (area < 0) area += mod;
    // cout << "area = " << area << endl;
    // i2 = i, j2 > j
    area += (sum(pf_j, i, j + 1, i, m) - j * sum(pf, i, j + 1, i, m)) * mul;
    area %= mod;
    if (area < 0) area += mod;
    // cout << "area = " << area << endl;
    // i2 < i, j2 = j
    area += (i * sum(pf, 1, j, i - 1, j) - sum(pf_i, 1, j, i - 1, j)) * mul;
    area %= mod;
    if (area < 0) area += mod;
    // cout << "area = " << area << endl;
    // i2 > i, j2 = j
    area += (sum(pf_i, i + 1, j, n, j) - i * sum(pf, i + 1, j, n, j)) * mul;
    area %= mod;
    if (area < 0) area += mod;
    // cout << "area = " << area << endl;
    // i2 = i, j2 = j
    area += mul * mul % mod * p[i][j];
    area %= mod;
    if (area < 0) area += mod;
    // cout << "area = " << area << endl;
    
    area = area * p[i][j] % mod * bindiv(1, pf[n][m]) % mod;
    return area;
}



signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> p[i][j];
            // prefix
            pf[i][j] = (pf[i][j - 1] + pf[i - 1][j] - pf[i - 1][j - 1] + p[i][j]) % mod;
            if (pf[i][j] < 0) pf[i][j] += mod;
            // prefix * i
            int val = p[i][j] * i % mod;
            pf_i[i][j] = (pf_i[i][j - 1] + pf_i[i - 1][j] - pf_i[i - 1][j - 1] + val) % mod;
            if (pf_i[i][j] < 0) pf_i[i][j] += mod;
            // prefix * j
            val = p[i][j] * j % mod;
            pf_j[i][j] = (pf_j[i][j - 1] + pf_j[i - 1][j] - pf_j[i - 1][j - 1] + val) % mod;
            if (pf_j[i][j] < 0) pf_j[i][j] += mod;
            // prefix * i * j
            val = p[i][j] * i * j % mod;
            pf_ij[i][j] = (pf_ij[i][j - 1] + pf_ij[i - 1][j] - pf_ij[i - 1][j - 1] + val) % mod;
            if (pf_ij[i][j] < 0) pf_ij[i][j] += mod;
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            int val = area(i, j);
            // // cout << "area " << i << " " << j << " = " << val << endl;
            ans = ans + val;
            if (ans >= mod) ans -= mod;
        }
    }
    cout << ans * bindiv(1, pf[n][m]) % mod;
}