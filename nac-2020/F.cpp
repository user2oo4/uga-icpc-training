#include <bits/stdc++.h>
using namespace std;
// #define int long long
typedef pair<int, int> ii;

const int maxN = 50 + 5;
int a[maxN][maxN];
int dp[maxN][maxN];
vector<ii> val[maxN * maxN];
int n, k;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            cin >> a[i][j];
            val[a[i][j]].push_back(ii(i, j));
            dp[i][j] = -1;
            if (a[i][j] == 1) dp[i][j] = 0;
        }
    }
    for (int v = 1 ; v < k ; v++) {
        for (ii tmp: val[v]) {
            int i = tmp.first;
            int j = tmp.second;
            if (dp[i][j] == -1) continue;
            // cout << "a " << i << " " << j << " = " << a[i][j] << endl;
            // cout << "dp " << i << " " << j << " = " << dp[i][j] << endl;
            for (ii tmp2: val[v + 1]) {
                int ni = tmp2.first;
                int nj = tmp2.second;
                if (dp[ni][nj] == -1) {
                    dp[ni][nj] = dp[i][j] + abs(ni - i) + abs(nj - j);
                }
                else dp[ni][nj] = min(dp[ni][nj], dp[i][j] + abs(ni - i) + abs(nj - j));
            }
        }
    }
    int ans = -1;
    for (ii tmp: val[k]) {
        int i = tmp.first;
        int j = tmp.second;
        if (dp[i][j] == -1) continue;
        if (ans == -1) ans = dp[i][j];
        else ans = min(ans, dp[i][j]);
    }
    cout << ans;
}