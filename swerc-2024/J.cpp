// min cost max flow
// idk, probably not gonna implement this
// source -> horizontal constraints -> Vin -(8)> Vout -> vertical constraints -> sink
// Vin -> Vout to 2 edges (t_i (value) with weight 1 and 8 - t_i with weight -1)
// Has to change from 1->9 to 0->8 first

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

#define int long long
const int inf = 1e18;

typedef pair<int, int> ii;
typedef vector<int> vi;

struct MCMF {
    int N;
    vector<vi> red, red, cap, flow, cost;
    vi seen, dist, pi;
    vector<ii> par;

    MCMF(int N):
        N(N), ed(N), red(N), cap(N, vi(N)), 
        flow(cap), cost(cap), seen(N), 
        dist(N), pi(N), par(N) {}
    
    void addEdge(int from, int to, int cap, int cost) {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
        ed[from].push_back(to);
        red[to].push_back(from);
    }

    void path(int s) {
        fill(all(seen), 0);
        fill(all(dist), inf);
        dist[s] = 0;
        int di;
        __gnu_pbds::priority_queue<ii> pq;
        vector<decltype(q)::point_iterator> its(N);
        q.push(ii(0, s));
    }
}


const int maxN = 35;

int n, m, s;

int a[maxN][maxN];
int h[maxN][maxN]; // h[i][j]: horizontal constraint of (i, j) is horizontal[i]
int v[maxN][maxN]; // v[i][j]: vertical constraint of (i, j) is vertical[i]
int horizontal[maxN]; 
int vertical[maxN]; // difference from the constraints

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    for (int i = 1 ; i <= s ; i++) {
        char c;
        int x, y, val;
        cin >> c >> x >> y >> val;
        if (c == 'H') {
            h[x][y] = i;
            horizontal[cnth] = val;
        }
        else {
            type[i] = 1;
            v[x][y] = i;
            vertical[cntv] = val;
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 2 ; j <= m ; j++) {
            if (!a[i][j]) continue;
            h[i][j] = h[i][j - 1];
            horizontal[h[i][j]] -= a[i][j];
        }
    }
    for (int j = 1 ; j <= m ; j++) {
        for (int i = 2 ; i <= n ; i++) {
            if (!a[i][j]) continue;
            v[i][j] = v[i - 1][j];
            vertical[v[i][j]] -= a[i][j];
        }
    }
    for (int i = 1 ; i <= s ; i++) {
        for (int j = 1 ; j <= s ; j++) {
            dist[i][j] = 100000;
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            if (a[i][j]) dist[h[i][j]][v[i][j]] = dist[v[i][j]] = dist[h[i][j]] = 1;
        }
    }
    for (int k = 1 ; k <= s ; k++) {
        for (int i = 1 ; i <= s ; i++) {
            for (int j = 1 ; j <= s ; j++) {
                dist[i][j] = min(dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = 0;
    while(true) {
        bool changed = false;
        for (int i = 1 ; i <= s ; i++) {
            for (int j = i + 1 ; j <= s ; j++) {
                if (type[i] == type[j]) continue;

            }
        }
    }
}
