#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int maxN = 2002;
const int maxM = 3003;
vector<int> AdjList[maxN];
int pset[maxN];
int sz[maxN];
bool taken[maxM];
bool in_tree[maxM];
vector<ii> edges;


int n, m;

void init() {
    for (int i = 1 ; i <= n ; i++) {
        sz[i] = 1;
        pset[i] = i;
    }
}

int find_set(int s) {
    if (s == pset[s]) return s;
    return pset[s] = find_set(pset[s]);
}

void union_set(int u, int v) {
    if (sz[u] < sz[v]) swap(u, v);
    pset[u] = v;
    sz[u] += sz[v];
}

bool vis[maxN];
void reset() {
    for (int i = 1 ; i <= n ; i++) vis[i] = 0;
}

void dfs(int s = 1, int p = -1) {
    vis[s] = 1;
    for (int i: AdjList[s]) {
        if (!in_tree[i]) continue;
        int u = edges[i].first + edges[i].second - s;
        if (u == p) continue;
        dfs(u, s);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    init();
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    edges.push_back(ii(0, 0));
    for (int i = 1 ; i <= m ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AdjList[u].push_back(i);
        AdjList[v].push_back(i);
        pq.push(ii(w, i));
        edges.push_back(ii(u, v));
        if (i <= n - 1) {
            in_tree[i] = 1;
        }
    }
    int ans = 0;
    while (!pq.empty()) {
        ii tmp = pq.top();
        pq.pop();
        int w = tmp.first;
        int i = tmp.second;
        int u = edges[i].first;
        int v = edges[i].second;
        int fu = find_set(u);
        int fv = find_set(v);
        // cout << "u v w " << u << " " << v << " " << w << endl;
        // cout << "fu fv " << fu << " " << fv << endl;
        if (fu == fv) continue;
        else {
            taken[i] = 1;
            if (i >= n) {
                ans++;
            }
            union_set(fu, fv);
        }
    }
    cout << ans << endl;
    for (int i = 1 ; i < n ; i++) {
        if (taken[i]) continue;
        // cout << "i = " << i << endl;
        in_tree[i] = 0;
        reset();
        dfs();
        for (int j = n ; j <= m ; j++) {
            if (taken[j] && !in_tree[j] && vis[edges[j].first] != vis[edges[j].second]) {
                in_tree[j] = 1;
                cout << i << " " << j << endl;
                ans--;
                if (!ans) return 0;
                break;
            }
        }
    }
}