#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a ; i < (b) ; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxN = 2002;
const int inf = 1e9 + 7;
vector<pii> AdjList[maxN];
int dist[maxN][maxN];
int edge[maxN][maxN];
int n, m, c;

int dijk(int s) {
    int ans = inf;
    dist[s][s] = 0;
    priority_queue<pii> pq;
    pq.push(pii(0, s));
    while (!pq.empty()) {
        int d = -pq.top().first;
        int u = pq.top().second;
        // cout << "d u = " << d << " " << u << endl;
        pq.pop();
        if (dist[s][u] != d) continue;
        for (pii tmp: AdjList[u]) {
            int v = tmp.first;
            int w = tmp.second;
            if (dist[s][v] > dist[s][u] + w) {
                dist[s][v] = dist[s][u] + w;
                pq.push(pii(-dist[s][v], v));
            }
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        if (!edge[i][s]) continue;
        ans = min(ans, dist[s][i] + edge[i][s]);
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> c;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            dist[i][j] = inf;
        }
    }
    bool ok = false;
    for (int i = 1 ; i <= m ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u][v] = w;
        if (w <= c) ok = true;
        AdjList[u].push_back(pii(v, w));
    }
    // cout << "ok = " << ok << endl;
    if (!ok) {
        cout << 0;
        return 0;
    }
    int res = inf;
    for (int i = 1 ; i <= n ; i++) {
        res = min(res, dijk(i));
    }
    if (res > c) cout << 1;
    else cout << 2;
}