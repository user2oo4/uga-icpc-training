#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int maxN = 2e5 + 5;
vector<int> AdjList[maxN];
int par[maxN][20];
int in[maxN];
int out[maxN];
int dist[maxN];
int n, q;
int cur;

void dfs(int s, int p = 0) {
    in[s] = ++cur;
    dist[s] = dist[p] + 1;
    par[s][0] = p;
    for (int i = 1 ; i < 20 ; i++) {
        par[s][i] = par[par[s][i - 1]][i - 1];
    }
    for (int u: AdjList[s]) {
        if (u == p) continue;
        dfs(u, s);
    }
    out[s] = ++cur;
}

bool anc(int a, int b) {
    if (!a) return true;
    if (!b) return false;
    return in[a] <= in[b] && out[a] >= out[b];
}

int lca(int u, int v) {
    if (anc(u, v)) return u;
    if (anc(v, u)) return v;
    for (int i = 19 ; i >= 0 ; i--) {
        if (!anc(par[u][i], v)) u = par[u][i];
    }
    return par[u][0];
}

int node(int u, int v) {
    int lc = lca(u, v);
    return dist[u] - dist[lc] + dist[v] - dist[lc] + 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 1 ; i < n ; i++) {
        int u, v;
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    dfs(1);
    while (q--) {
        int u, v;
        cin >> u >> v;
        int nodes = node(u, v);
        cout << 1ll * nodes * (nodes - 1) / 2 + n << endl;
    }
}