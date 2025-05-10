#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) {
    return rng() % (r - l + 1) + l;
}

const int maxN = 1005;
int r, c, n, p;
ii pos[maxN * maxN];
int a[maxN][maxN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool ok(int x, int y) {
    return x >= 1 && x <= r && y >= 1 && y <= c;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> r >> c >> n >> p;
    for (int i = 1 ; i <= r ; i++) {
        for (int j = 1 ; j <= c ; j++) {
            cin >> a[i][j];
            pos[a[i][j]] = ii(i, j);
        }
    }
    set<int> S;
    for (int i = 1 ; i <= p ; i++) {
        int cx = pos[i].first;
        int cy = pos[i].second;
        for (int dir = 0 ; dir < 4 ; dir++) {
            if (ok(cx + dx[dir], cy + dy[dir]) && a[cx + dx[dir]][cy + dy[dir]]) {
                int d = a[cx + dx[dir]][cy + dy[dir]] - i;
                if (p + d >= 1 && p + d <= n) S.insert(d);
            }
        }
    }
    int ans = (int)S.size();
    cout << ans << "/" << n - 1 << endl;
}