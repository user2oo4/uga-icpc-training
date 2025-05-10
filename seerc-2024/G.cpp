#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int maxN = 1e6 + 5;
int a[maxN];
int dp[maxN][2];
map<int, int> M;
int n;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    int cnt = 0;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        if (!M[a[i]]) M[a[i]] = ++cnt;
        a[i] = M[a[i]];
        dp[a[i]][0] = -1;
        dp[a[i]][1] = -1;
    }
    int best_1 = 0;
    for (int i = 1 ; i <= n ; i++) {
        dp[a[i]][1] = max(dp[a[i]][1] + 1, dp[a[i]][0] + 1);
        dp[a[i]][0] = max(dp[a[i]][0], best_1 + 1);
        // cout << "a " << i << " = " << a[i] << endl;
        // cout << "dp 0 1 = " << dp[a[i]][0] << " " << dp[a[i]][1] << endl;
        best_1 = max(dp[a[i]][1], best_1);
    }
    cout << best_1;
}