#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 2e5 + 5;
const int inf = 1e18;
int a[maxN], b[maxN], c[maxN];
int n, m, q;

int pf_a[maxN];
int pf_bc[maxN];
int pf_b[maxN];
int pf_ac[maxN];

int find(int A, int B) {
    // Ax^2 + Bx
    int l = 0;
    int r = m;
    while (r - l > 3) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int res1 = A * m1 * m1 + B * m1;
        int res2 = A * m2 * m2 + B * m2;
        // cout << "m1 m2 res1 res2 = " << m1 << " " << m2 << " " << res1 << " " << res2 << endl;
        if (res1 > res2) {
            r = m2;
        } else l = m1;
    }
    int ans = -inf;
    for (int i = l ; i <= r ; i++) {
        // cout << "i " << i << endl;
        // cout << "A * i * i + B * i = " << A * i * i + B * i << endl;
        ans = max(ans, A * i * i + B * i);
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i] >> b[i] >> c[i];
        pf_a[i] = pf_a[i - 1] + a[i];
        pf_b[i] = pf_b[i - 1] + b[i];
        pf_bc[i] = pf_bc[i - 1] + b[i] * c[i];
        pf_ac[i] = pf_ac[i - 1] + a[i] * c[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int C = -(pf_ac[r] - pf_ac[l - 1]);
        int B = pf_bc[r] - pf_bc[l - 1] + pf_a[r] - pf_a[l - 1];
        int A = -(pf_b[r] - pf_b[l - 1]);
        // find max x in [0, m] (Ax^2 + Bx + C)
        // cout << "l r " << l << " " << r << endl;
        // cout << "A B C = " << A << " " << B << " " << C << endl;
        cout << find(A, B) + C << endl;
    }
}