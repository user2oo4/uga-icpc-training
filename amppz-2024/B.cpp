#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e15;
const int maxN = 404;
int cost[maxN][maxN][3];

int n, m;


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if (i == j) continue;
            cost[i][j][0] = cost[i][j][1] = cost[i][j][2] = inf;
        }
    }
    for (int i = 1 ; i <= m ; i++) {
        int u, v, w, t;
        cin >> u >> v >> w >> t;
        for (int x = t ; x >= 0 ; x--) {
            cost[u][v][x] = min(cost[u][v][x], w);
        }
    }
    for (int k = 1 ; k <= n ; k++) {
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                cost[i][j][0] = min(cost[i][j][0], cost[i][k][0] + cost[k][j][0]);
                cost[i][j][1] = min(cost[i][j][1], cost[i][k][1] + cost[k][j][1]);
                cost[i][j][2] = min(cost[i][j][2], cost[i][k][2] + cost[k][j][2]);
            }
        }
    }
    for (int cnt = 0 ; cnt < 10 ; cnt++) {
        for (int k = 1 ; k <= n ; k++) {
            for (int i = 1 ; i <= n ; i++) {
                for (int j = 1 ; j <= n ; j++) {
                    cost[i][j][2] = min(cost[i][j][2], cost[i][k][2] + cost[k][j][1] * 2 + cost[j][k][0]);
                }
            }
        }for (int k = 1 ; k <= n ; k++) {
            for (int i = 1 ; i <= n ; i++) {
                for (int j = 1 ; j <= n ; j++) {
                    cost[i][j][2] = min(cost[i][j][2], cost[i][k][2] + cost[k][j][2]);
                }
            }
        }    
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if (cost[i][j][2] == inf) cost[i][j][2] = -1;
            cout << cost[i][j][2] << " ";
        }
        cout << endl;
    }
}