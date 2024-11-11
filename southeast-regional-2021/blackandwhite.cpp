#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const int maxN = 20 + 1;
const int maxMask = (1 << 20) + 1;
int n;
ld p[maxN];
ld dp[maxMask];
ld mul[maxMask];
ld revmul[maxMask];
ld prob[maxMask][maxN]; 
// the probability of going from a mask and drop a certain bit

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> p[i];
        // cout << "p " << i << " = " << p[i] << endl;
    }
    for (int mask = 0 ; mask < (1 << n) ; mask++) {
        mul[mask] = revmul[mask] = 1;
        for (int i = 0 ; i < n ; i++) {
            if (mask & (1 << i)) {
                mul[mask] *= p[i];
                revmul[mask] *= (1 - p[i]);
            }
        }
        // cout << "mul revmul " << mask << " = " << mul[mask] << " " << revmul[mask] << endl;
    }
    for (int mask = 0 ; mask < (1 << n) ; mask++) {
        if (__builtin_popcount(mask) <= 2) {
            dp[mask] = 0;
            continue;
        }
        ld total_rate = 0;
        for (int i = 0 ; i < n ; i++) {
            if (!(mask & (1 << i))) continue;
            // mask has bit i
            int submask = mask ^ (1 << i);
            ld rate = mul[submask] * (1 - p[i]) + revmul[submask] * p[i];
            // cout << "submask rate = " << submask << " " << rate << endl;
            total_rate += rate;
            dp[mask] += dp[submask] * rate;
        }
        dp[mask] /= total_rate;
        dp[mask] += (1.0 / total_rate);
        // cout << "dp " << mask << " = " << dp[mask] << endl;
    }
    cout << fixed << setprecision(10) << dp[(1 << n) - 1];
}