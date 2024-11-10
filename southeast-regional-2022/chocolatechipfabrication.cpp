#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
typedef pair<int, int> ii;
const int maxN = 1e3 + 5;
int n, m;
char c[maxN][maxN];
int a[maxN][maxN];
int dist[maxN][maxN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool ck(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> c[i][j];
            if (c[i][j] == 'X') a[i][j] = 1;
        }
    }
    // 0->n+1
    // 0->m+1
    n += 2;
    m += 2;
    queue<ii> q;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (!a[i][j]) {
                dist[i][j] = 0;
                q.push(ii(i, j));
            } else {
                dist[i][j] = -1;
            }
        }
    }
    int ans = 0;
    while(!q.empty()) {
        int cx = q.front().fi;
        int cy = q.front().se;
        q.pop();
        ans = max(ans, dist[cx][cy]);
        for (int dir = 0 ; dir < 4 ; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (!ck(nx, ny)) continue;
            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push(ii(nx, ny));
            }
        }
    }
    cout << ans;
}