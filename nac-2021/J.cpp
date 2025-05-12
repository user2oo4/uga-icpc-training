#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int inf = 1e9 + 7;
const int maxN = 105;
int dp[maxN][26];
int cost[26][26];
int n, k;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) {
        string s; int c;
        cin >> s >> c;
        cost[s[0] - 'a'][s[1] - 'a'] = c;
    }
    for (int i = 0 ; i <= k ; i++) {
        for (int j = 0 ; j < 26 ; j++) {
            dp[i][j] = inf;
        }
    }
    if (k & 1) {
        for (int i = 0 ; i < 26 ; i++) {
            dp[1][i] = 0;
        }
    }
    else {
        for (int i = 0 ; i < 26 ; i++) {
            if (cost[i][i]) dp[2][i] = cost[i][i];
        }
    }
    int ans = inf;
    for (int len = 1 ; len <= k ; len++) {
        for (int c = 0 ; c < 26 ; c++) {
            if (dp[len][c] == inf) continue;
            // cout << "dp " << len << " " << c << " = " << dp[len][c] << endl;
            if (len == k) {
                ans = min(ans, dp[len][c]);
                // cout << "ans = " << ans << endl;
            }
            for (int nc = 0 ; nc < 26 ; nc++) {
                if (cost[c][nc] && cost[nc][c]) {
                    dp[len + 2][nc] = min(dp[len + 2][nc], dp[len][c] + cost[c][nc] + cost[nc][c]);
                }
            }
        }
    }
    if (ans == inf) cout << -1;
    else cout << ans;
}