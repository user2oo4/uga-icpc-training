#include <bits/stdc++.h>
using namespace std;

const int maxN = 5005;
const int maxK = maxN * 2;
const int inf = maxK;
int dp[maxN][maxK];
int mn[maxN][maxK];

int n;
int a[maxN];
vector<int> AdjList[maxN];

void dfs(int s, int p = -1) {
    for (int i = 2 ; i < maxK ; i++) {
        dp[s][i] = (a[s] == i)? 0: i;
        mn[s][i] = maxK;
    }
    for (int u: AdjList[s]) {
        if (u == p) continue;
        dfs(u, s);
    }
    for (int u: AdjList[s]) {
        if (u == p) continue;
        for (int i = 2 ; i < maxK ; i++) {
            for (int j = i ; j < maxK ; j += i) {
                // update dp[s][j] from dp[u][i]
                mn[u][j] = min(mn[u][j], dp[u][i]);
            }
        }
    }

    for (int i = 2 ; i < maxK ; i++) {
        for (int u: AdjList[s]) {
            if (u == p) continue;
            dp[s][i] += mn[u][i];
        }
        // cout << "equal " << s << " " << i << " = " << dp[s][i] << endl;
    }
    
    
    for (int i = 2 ; i < maxK ; i++) {
        for (int j = i ; j < maxK ; j += i) {
            dp[s][i] = min(dp[s][i], dp[s][j]);
        }
        // cout << "divisible " << s << " " << i << " = " << dp[s][i] << endl;
    }
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    for (int i = 1 ; i < n ; i++) {
        int u, v;
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    dfs(1);
    int ans = dp[1][2];
    for (int i = 3 ; i < maxK ; i++) {
        ans = min(ans, dp[1][i]);
    }
    cout << ans;
}