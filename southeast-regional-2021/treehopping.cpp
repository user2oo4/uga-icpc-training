#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxN = 1e5 + 5;

int tc;
int n;

vector<int> AdjList[maxN];
int perm[maxN];
int dist[maxN];
int in[maxN];
int out[maxN];
int par[maxN][20];
int cur_time;

bool is_child(int u, int s) {
    if (s == 0) return true;
    return in[s] <= in[u] && out[s] >= out[u];
}

int lca(int u, int v) {
    if (is_child(u, v)) return v;
    else if (is_child(v, u)) return u;
    for (int i = 19 ; i >= 0 ; i--) {
        if (!is_child(u, par[v][i])) v = par[v][i];
    }
    return par[v][0];
}

int calc_dist(int u, int v) {
    int lc = lca(u, v);
    // cout << "lca " << u << " " << v << " = " << lc << endl;
    return dist[u] + dist[v] - 2 * dist[lc];
}

void dfs(int s, int p = 0) {
    in[s] = ++cur_time;
    if (p) {
        par[s][0] = p;
        // cout << "par " << s << " " << 0 << " = " << p << endl;
        for (int j = 1 ; j < 20 ; j++) {
            par[s][j] = par[par[s][j - 1]][j - 1];
            // cout << "par " << s << " " << j << " = " << par[s][j] << endl;
            if (par[s][j] == 0) break;
        }
    }
    for (int u: AdjList[s]) {
        if (u == p) continue;
        dist[u] = dist[s] + 1;
        dfs(u, s);
    }
    out[s] = ++cur_time;
}

signed main() {
    cin >> tc;
    while(tc--) {
        cin >> n;
        // Initialize shit
        cur_time = 0;
        for (int i = 1 ; i <= n ; i++) {
            AdjList[i].clear();
            in[i] = out[i] = dist[i] = 0;
        }
        for (int i = 1 ; i < n ; i++) {
            int u, v;
            cin >> u >> v;
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }
        for (int i = 1 ; i <= n ; i++) {
            cin >> perm[i];
        }
        dfs(1);
        bool answer = 1;
        for (int i = 1 ; i < n ; i++) {
            if (calc_dist(perm[i], perm[i + 1]) > 3) {
                answer = 0;
                break;
            }
        }
        cout << answer << endl;
    }
}