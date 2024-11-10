#include <bits/stdc++.h>
using namespace std;

const int maxN = 1005;
const int inf = 1e6 + 5;
int n, d;
int a[maxN];
int b[maxN];
bool vis[maxN];
int dp[maxN][maxN]; // minimum trash on day x with y days of cleaning



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> d;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1 ; i <= d ; i++) {
        int x;
        cin >> x;
        vis[x] = 1;
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j <= i ; j++) {
            dp[i][j] = inf;
            if (j != i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i]);
            if (j) {
                dp[i][j] = min(dp[i][j], max(0, dp[i - 1][j - 1] + a[i] - b[i]));
            }
            // cout << dp[i][j] << endl;
            if (vis[i]) {
                if (dp[i][j]) dp[i][j] = inf;
            }
            if (i == n && dp[i][j] != inf) {
                cout << j;
                return 0;
            } 
            // cout << "dp " << i << " " << j << " = " << dp[i][j] << endl;
        }
        if (vis[i] && dp[i][i]) {
            cout << -1;
            return 0;
        }
    }
    cout << -1;
}