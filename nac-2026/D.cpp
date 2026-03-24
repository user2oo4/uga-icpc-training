#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int n, k;
int a[4];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0 ; i <= k ; i++) {
        cin >> a[i];
    }
    vector<vector<vector<ld>>> dp;
    dp.assign(a[0] + 2, vector<vector<ld>>(a[2] + 2, vector<ld>(a[3] + 2, 0.0)));

    if (a[2] * 2 + a[3] * 3 + 1 < n - a[1]) {
        cout << 0;
        return 0;
    }

    for (int c0 = a[0] ; c0 >= 0 ; c0--) {
        for (int c2 = a[2] ; c2 >= 0 ; c2--) {
            for (int c3 = a[3] ; c3 >= 0 ; c3--) {
                int drawn = c0 + c2 + c3;
                int sum = c2 * 2 + c3 * 3;
                if (drawn == a[0] + a[2] + a[3]) {
                    if (sum >= drawn) dp[c0][c2][c3] = 1.0;
                    else dp[c0][c2][c3] = 1.0 - a[1] * 1.0 / n;
                    // k = c0 + c2 + c3
                    // k/(k+1) * (k+1)/(k+2) * .... * (n-1)/n
                    // k/n = (1-a[1]) / n
                }
                else if (sum < drawn) dp[c0][c2][c3] = 0.0;
                else {
                    int l0 = a[0] - c0;
                    int l2 = a[2] - c2;
                    int l3 = a[3] - c3;
                    int left = l0 + l2 + l3;
                    dp[c0][c2][c3] = dp[c0 + 1][c2][c3] * l0 * 1.0 / left + 
                    dp[c0][c2 + 1][c3] * l2 * 1.0 / left + dp[c0][c2][c3 + 1] * l3 * 1.0 / left;
                }
                // cout << "dp " << c0 << " " << c2 << " " << c3 << " = " << dp[c0][c2][c3] << endl;
            }
        }
    }

    cout << fixed << setprecision(9) << dp[0][0][0];

}