#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int maxN = 1e5 + 5;
int n, m;
vector<ii> AdjList[maxN];
unordered_map<int, int> g[maxN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AdjList[u].push_back(ii(v, w));
        AdjList[v].push_back(ii(u, w));
    }
    for (int u = 1 ; u <= n ; u++) {
        for (auto[v, w]: AdjList[u]) {
            if (AdjList[u].size() < AdjList[v].size() || (AdjList[u].size() == AdjList[v].size() && u < v)) {
                g[u][v] = w; // the size of this is a lot smaller but what's the real bound?
            }
        }
    }
    int ans = -1;
    for (int u = 1 ; u <= n ; u++) {
        for (auto[v, w1]: g[u]) {
            for (auto[k, w2]: g[v]) {
                if (g[u].find(k) != g[u].end()) ans = max(ans, w1 + w2 + g[u][k]);
            }
        }
    }
    cout << ans;
}