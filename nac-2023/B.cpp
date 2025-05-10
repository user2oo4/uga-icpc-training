#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int maxN = 5e4 + 5;

vector<int> AdjList[maxN];
int par[maxN][20];
int in[maxN], out[maxN];
int n, q;
ii edge1 = ii(0, 0);
ii edge2 = ii(0, 0);

int curTime = 0;
bool isParent(int u, int v) {
    if (!u) return true;
    if (!v) return false;
    return in[u] <= in[v] && out[u] >= out[v];
}
int lca(int u, int v) {
    if (isParent(u, v)) return u;
    if (isParent(v, u)) return v;
    for (int i = 19 ; i >= 0 ; i--) {
        if (!isParent(par[u][i], v)) u = par[u][i];
    }
    return par[u][0];
}
void dfs(int s, int p = 0) {
    // cout << "dfs " << s << " " << p << endl;
    in[s] = ++curTime;
    par[s][0] = p;
    for (int i = 1 ; i < 20 ; i++) {
        par[s][i] = par[par[s][i - 1]][i - 1];
    }
    for (int u: AdjList[s]) {
        if (u == p) continue;
        else if (in[u]) {
            if (!edge1.first) edge1 = ii(u, s);
            else if (edge1 != ii(s, u)) edge2 = ii(u, s);
            continue;
        }
        dfs(u, s);
    }
    out[s] = ++curTime;
}

bool cross(int u1, int v1, int u2, int v2) {
    // check if u1-v1 will cross u2-v2
    int lc1 = lca(u1, v1);
    int lc2 = lca(u2, v2);
    if (isParent(u2, u1) && isParent(lc1, u2)) return true;
    if (isParent(lc2, u1) && isParent(lc1, lc2)) return true;
    if (isParent(u1, u2) && isParent(lc2, u1)) return true;
    if (isParent(lc1, u2) && isParent(lc2, lc1)) return true;
    
    if (isParent(v2, u1) && isParent(lc1, v2)) return true;
    if (isParent(lc2, u1) && isParent(lc1, lc2)) return true;
    if (isParent(u1, v2) && isParent(lc2, u1)) return true;
    if (isParent(lc1, v2) && isParent(lc2, lc1)) return true;

    if (isParent(u2, v1) && isParent(lc1, u2)) return true;
    if (isParent(lc2, v1) && isParent(lc1, lc2)) return true;
    if (isParent(v1, u2) && isParent(lc2, v1)) return true;
    if (isParent(lc1, u2) && isParent(lc2, lc1)) return true;
    
    if (isParent(v2, v1) && isParent(lc1, v2)) return true;
    if (isParent(lc2, v1) && isParent(lc1, lc2)) return true;
    if (isParent(v1, v2) && isParent(lc2, v1)) return true;
    if (isParent(lc1, v2) && isParent(lc2, lc1)) return true;

    return false;
}

int solve(int u, int v) {
    int ans = 1;
    // edge1 only
    if (!cross(u, edge1.first, edge1.second, v)) ans++;
    if (!cross(u, edge1.second, edge1.first, v)) ans++;
    // edge2 only
    if (!cross(u, edge2.first, edge2.second, v)) ans++;
    if (!cross(u, edge2.second, edge2.first, v)) ans++;
    // edge1 then edge2
    if (!cross(u, edge1.first, edge1.second, edge2.first) &&
        !cross(edge1.second, edge2.first, edge2.second, v) &&
        !cross(u, edge1.first, edge2.second, v)) {
            // cout << u << " " << edge1.first << " " << edge1.second << " " << edge2.first << " " << edge2.second << " " << v << endl;
            ans++;
        }
    if (!cross(u, edge1.second, edge1.first, edge2.first) &&
        !cross(edge1.first, edge2.first, edge2.second, v) &&
        !cross(u, edge1.second, edge2.second, v)) {
            // cout << u << " " << edge1.second << " " << edge1.first << " " << edge2.first << " " << edge2.second << " " << v << endl;
            ans++;
        }
    if (!cross(u, edge1.first, edge1.second, edge2.second) &&
        !cross(edge1.second, edge2.second, edge2.first, v) &&
        !cross(u, edge1.first, edge2.first, v)) {
            // cout << u << " " << edge1.first << " " << edge1.second << " " << edge2.second << " " << edge2.first << " " << v << endl;
            ans++;
        }
    if (!cross(u, edge1.second, edge1.first, edge2.second) &&
        !cross(edge1.first, edge2.second, edge2.first, v) &&
        !cross(u, edge1.second, edge2.first, v)) {
            // cout << u << " " << edge1.second << " " << edge1.first << " " << edge2.second << " " << edge2.first << " " << v << endl;
            ans++;
        }
    // edge2 then edge1
    if (!cross(u, edge2.first, edge2.second, edge1.first) &&
        !cross(edge2.second, edge1.first, edge1.second, v) &&
        !cross(u, edge2.first, edge1.second, v)) {
            // cout << u << " " << edge2.first << " " << edge2.second << " " << edge1.first << " " << edge1.second << " " << v << endl;
            ans++;
        }
    if (!cross(u, edge2.second, edge2.first, edge1.first) &&
        !cross(edge2.first, edge1.first, edge1.second, v) &&
        !cross(u, edge2.second, edge1.second, v)) {
            // cout << u << " " << edge2.second << " " << edge2.first << " " << edge1.first << " " << edge1.second << " " << v << endl;
            ans++;
        }
    if (!cross(u, edge2.first, edge2.second, edge1.second) &&
        !cross(edge2.second, edge1.second, edge1.first, v) &&
        !cross(u, edge2.first, edge1.first, v)) {
            // cout << u << " " << edge2.first << " " << edge2.second << " " << edge1.second << " " << edge1.first << " " << v << endl;
            ans++;
        }
    if (!cross(u, edge2.second, edge2.first, edge1.second) &&
        !cross(edge2.first, edge1.second, edge1.first, v) &&
        !cross(u, edge2.second, edge1.first, v)) {
            // cout << u << " " << edge2.second << " " << edge2.first << " " << edge1.second << " " << edge1.first << " " << v << endl;
            ans++;
        } 

    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> q;
    for (int i = 1 ; i < n + 2 ; i++) {
        int u, v;
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    dfs(1);
    // cout << "edge1 " << edge1.first << " " << edge1.second << endl;
    // cout << "edge2 " << edge2.first << " " << edge2.second << endl;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << solve(u, v) << endl;
    }
}