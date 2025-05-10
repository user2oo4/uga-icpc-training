#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;

const int maxN = 5005;
const int maxK = 22;

int n, k;

pair<int, int> d[maxN]; // d and id
int dp[maxN][maxK];
int par[maxN][maxK];
int pf[maxN];
int pf_sq[maxN];
int ans[maxN];

int calc(int l, int r) {
    // cost of delivering a[l] to a[r]
    // sum(a[i]^2) - 2*sum(a[i]) + a[r]^2*(r-l+1)
    return (pf_sq[r] - pf_sq[l - 1]) - 2 * d[r].first * (pf[r] - pf[l - 1]) + d[r].first * d[r].first * (r - l + 1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> k;
    k = min(k, n);
    for (int i = 1 ; i <= n ; i++) {
        cin >> d[i].first;
        d[i].second = i;
        for (int j = 0 ; j <= k ; j++) {
            dp[i][j] = inf;
        }
    }
    sort(d + 1, d + 1 + n);
    for (int i = 1 ; i <= n ; i++) {
        pf[i] = pf[i - 1] + d[i].first;
        pf_sq[i] = pf_sq[i - 1] + d[i].first * d[i].first;
    }

    dp[0][0] = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < k ; j++) {
            if (dp[i][j] == inf) continue;
            for (int nx = i + 1 ; nx <= n ; nx++) {
                int cost = calc(i + 1, nx);
                if (dp[nx][j + 1] > dp[i][j] + cost) {
                    dp[nx][j + 1] = dp[i][j] + cost;
                    par[nx][j + 1] = i;
                }
            }
        }
    }
    // cout << dp[n][k] << endl;
    int cur_i = n;
    int cur_j = k;
    while (cur_i) {
        int new_cur_i = par[cur_i][cur_j];
        for (int i = cur_i ; i > new_cur_i ; i--) {
            ans[d[i].second] = d[cur_i].first;
        }
        cur_i = new_cur_i;
        cur_j--;
    }
    for (int i = 1 ; i <= n ; i++) {
        cout << ans[i] << " ";
    }
}