#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int maxN = 3e5 + 5;
int n, m;
vector<iii> edges;
int D[maxN];

int pset[maxN];
int sz[maxN];
int add[maxN];
int ans[maxN];

void init() {
    for (int i = 1 ; i <= n ; i++) {
        sz[i] = 1;
        pset[i] = i;
        add[i] = 0;
        ans[i] = 0;
    }
}

int find_set(int s) {
    if (s == pset[s]) return s;
    else {
        int fs = find_set(pset[s]);
        if (fs != pset[s]) {
            ans[s] += add[pset[s]];
            add[s] += add[pset[s]];
            pset[s] = fs;
        }
        return fs;
    }
}

void union_set(int u, int v, int k) {
    if (sz[u] > sz[v]) swap(u, v);
    // merge u into v
    add[u] += k * (sz[v] - sz[u]) - add[v];
    add[v] += k * sz[u];
    ans[u] += add[u];
    pset[u] = v;
    sz[v] += sz[u];
    // cout << "union " << u << " " << v << " " << k << endl;
    // cout << "add " << u << " = " << add[u] << endl;
    // cout << "ans " << u << " = " << ans[u] << endl;
    // cout << "add " << v << " = " << add[v] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    init();
    for (int i = 1 ; i <= n ; i++) {
        cin >> D[i];
        ans[i] = D[i];
    }
    for (int i = 1 ; i <= m ; i++) {
        int u, v;
        cin >> u >> v;
        int w = max(D[u], D[v]);
        edges.push_back(iii(w, ii(u, v)));
    }
    sort(edges.begin(), edges.end());
    for (iii tmp: edges) {
        int w = tmp.first;
        int fu = find_set(tmp.second.first);
        int fv = find_set(tmp.second.second);
        if (fu == fv) continue;
        union_set(fu, fv, w);
    }
    for (int i = 1 ; i <= n ; i++) {
        int fi = find_set(i);
        ans[i] += add[fi];
        cout << ans[i] << ' ';
    }
}