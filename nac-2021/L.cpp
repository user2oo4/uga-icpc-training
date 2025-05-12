#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> ii;

const int INF = 1e18 + 1;

int n, m, k, parent[200200];
int times[200200], dist[200200];
vector<ii> AdjList[200200];
priority_queue<ii> pq;
ii dp[200200];

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        AdjList[a].push_back({b, c});
    }
    for (int i = 1; i <= k; i++) cin >> times[i];
    sort(times + 1, times + k + 1);
    if (times[1] != 0) times[++k] = 0, sort(times + 1, times + k + 1);
    times[k + 1] = INF + 1;

    fill(dist + 2, dist + n + 1, INF);
    pq.push({0, 1});

    vector<int> order;
    while (!pq.empty()) {
        auto [c, u] = pq.top(); pq.pop();
        if (-c > dist[u]) continue;
        order.push_back(u);
        for (auto [x, y] : AdjList[u]) {
            if (dist[x] > y - c) {
                dist[x] = y - c;
                pq.push({c - y, x});
            }
        }
    }

    dp[1] = {1, 1};
    int ans = 0, l = 0;

    for (auto u : order) if (dp[u].first) {
        auto [a, b] = dp[u];
        for (auto [x, y] : AdjList[u]) if (dist[u] + y == dist[x]) {
            if (dist[x] > times[a + 1]) continue;
            parent[x] = u;
            dp[x].first = (dist[x] == times[a + 1] ? a + 1 : a);
            dp[x].second = min(2LL, dp[x].second + b);
        }
    }

    ans = (dp[n].first == k ? dp[n].second : 0);
    l = n;

    if (ans == 0) return cout << ans, 0;
    if (ans > 1) return cout << 1, 0;

    vector<int> path;
    while (l) path.push_back(l), l = parent[l];
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (auto x : path) cout << x << "\n";
}
