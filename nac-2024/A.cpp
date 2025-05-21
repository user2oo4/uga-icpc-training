#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int maxN = 51;
const int maxA = 1e5 + 5;
const int inf = 1e9 + 7;

int dp[2][maxN * maxA];
int n;
int a[maxN];
int b[maxN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0 ; i < maxN * maxA ; i++) {
        dp[0][i] = dp[1][i] = inf;
    }
    dp[0][0] = 0;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1 ; i <= n ; i++) {
        // cout << "i = " << i << endl;
        for (int j = 0 ; j < maxN * maxA ; j++) {
            if (dp[0][j] == inf) continue;
            // cout << "dp " << i - 1 << " " << j << " = " << dp[0][j] << endl;
            dp[1][j] = min(dp[1][j], dp[0][j] + b[i]);
            dp[1][j + a[i]] = min(dp[1][j + a[i]], dp[0][j]);
        }
        for (int j = 0 ; j < maxN * maxA ; j++) {
            dp[0][j] = dp[1][j];
            dp[1][j] = inf;
        }
    }
    int ans = inf;
    for (int j = 0 ; j < maxN * maxA ; j++) {
        ans = min(ans, max(dp[0][j], j));
    }
    cout << ans;
}