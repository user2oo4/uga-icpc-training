#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) {
    return rng() % (r - l + 1) + l;
}

const int inf = 1e9;
const int maxN = 505;
int n;
int dp[maxN][maxN];
int a[maxN];
int pos[maxN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        pos[a[i]] = i;
        for (int j = 1 ; j <= n ; j++) {
            dp[i][j] = inf;
        }
    }
    for (int i = n ; i >= 1 ; i--) {
        for (int j = i ; j <= n ; j++) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            for (int k = i ; k < j ; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + abs(pos[k + 1] - pos[i]));
            }
        }
    }
    cout << dp[1][n];
}