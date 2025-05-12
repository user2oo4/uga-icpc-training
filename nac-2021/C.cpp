#include <bits/stdc++.h>
using namespace std;
// #define int long long
typedef pair<int, int> ii;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int maxN = 5e6 + 6;
int n, m, k;
vector<vector<bool>> bl;
vector<vector<int>> pf;
vector<vector<bool>> ok; // check if it's possible to place robot at this square as the top left square
vector<vector<int>> rev_pf;
vector<vector<int>> r;
vector<vector<bool>> vis;

int get_sum(int i1, int j1, int i2, int j2) {
    return pf[i2][j2] - pf[i2][j1 - 1] - pf[i1 - 1][j2] + pf[i1 - 1][j1 - 1];
}

bool solve(int s) {
    // side of square = s
    // cout << "s = " << s << endl;
    ok.assign(n + 1, vector<bool>(m + 1, false));
    rev_pf.assign(n + 1, vector<int>(m + 1, 0));
    r.assign(n + 1, vector<int>(m + 1, 0));
    vis.assign(n + 1, vector<bool>(m + 1, false));
    if (!s) return true;
    queue<ii> q;
    for (int i = 1 ; i + s - 1 <= n ; i++) {
        for (int j = 1 ; j + s - 1 <= m ; j++) {
            ok[i][j] = (!get_sum(i, j, i + s - 1, j + s - 1));
            if (ok[i][j]) {
                // cout << "i j " << i << " " << j << endl;
                r[i][j]++;
                if (q.empty()) {
                    vis[i][j] = 1;
                    q.push(ii(i, j));
                }
            } 
        }
    }
    if (q.empty()) return false;
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int d = 0 ; d < 4 ; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && ok[nx][ny] && !vis[nx][ny]) {
                q.push(ii(nx, ny));
                vis[nx][ny] = 1;
            }
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            if (ok[i][j] && !vis[i][j]) return false;
            rev_pf[i][j] = rev_pf[i - 1][j] + rev_pf[i][j - 1] - rev_pf[i - 1][j - 1] + r[i][j];
            int si = max(1, i - s + 1);
            int sj = max(1, j - s + 1);
            int val = rev_pf[i][j] - rev_pf[si - 1][j] - rev_pf[i][sj - 1] + rev_pf[si - 1][sj - 1];
            // cout << rev_pf[i][j] << " ";
            if (!val && !bl[i][j]) return false;
        }
        // cout << endl;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    bl.assign(n + 1, vector<bool>(m + 1, false));
    pf.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 1 ; i <= k ; i++) {
        int x, y;
        cin >> x >> y;
        bl[x][y] = true;
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            pf[i][j] = pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1] + bl[i][j];
        }
    }
    int l = 0;
    int r = min(n, m);
    while (l < r) {
        // cout << "l r " << l << " " << r << endl;
        int mid = (l + r + 1) / 2;
        if (solve(mid)) l = mid;
        else r = mid - 1;
    }
    if (!l) cout << -1;
    else cout << l;
}