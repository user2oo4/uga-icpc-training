#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxN = 50 + 5;
const int maxK = 20;

int dp[maxN][maxN][maxN][maxK]; 
// current, last 2, selected
int n, k;
int a[maxN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    dp[0][0][0][0] = 1;
    int ans = 0;
    for (int i = 0 ; i <= n ; i++) {
        for (int l1 = 0 ; l1 <= n ; l1++) {
            for (int l2 = 0 ; l2 <= n ; l2++) {
                for (int j = 0 ; j <= k ; j++) {
                    if (!dp[i][l1][l2][j]) continue;
                    // cout << "dp " << i << " " << l1 << " " << l2 << " " << j << " = " << dp[i][l1][l2][j] << endl;
                    if (j == k) {
                        ans += dp[i][l1][l2][j];
                        continue;
                    }
                    for (int nxt = i + 1 ; nxt <= n ; nxt++) {
                        // cout << "a " << nxt << " = " << a[nxt] << endl;
                        if (j < 2 || a[nxt] <= a[i] + a[l1]) {
                            dp[nxt][i][l1][j + 1] += dp[i][l1][l2][j];
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}