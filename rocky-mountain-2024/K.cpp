#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 6;
int n, g, d, m; 
// n: ingredients so far
// g: no. of genres 
// d: dependencies
// m: max ingredients

vector<int> ing;
queue<int> q;
int vis[maxN];
vector<int> genre[maxN]; // all genres of a certain ingredient
vector<int> AdjList[maxN];
int cnt[maxN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    cin >> n >> g >> d >> m;
    for (int i = 1 ; i <= n ; i++) {
        int u; cin >> u;
        vis[u] = 1;
        ing.push_back(u);
        q.push(u);
    }
    for (int i = 1 ; i <= g ; i++) {
        int k;
        cin >> k;
        for (int j = 0 ; j < k ; j++) {
            int x;
            cin >> x;
            genre[x].push_back(i);
            // cout << "x i " << x << " " << i << endl;
        }
    }
    for (int i = 1 ; i <= d ; i++) {
        int u, v;
        cin >> u >> v;
        AdjList[u].push_back(v);
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        m--;
        if (m < 0) {
            cout << "disaster";
            return 0;
        }
        for (int u: AdjList[t]) {
            if (!vis[u]) {
                q.push(u);
                ing.push_back(u);
                vis[u] = 1;
            }
        }
    }
    for (int u: ing) {
        // cout << "u = " << u << endl;
        for (int v: genre[u]) {
            // cout << "v = " << v << endl;
            cnt[v]++;
        }
    }
    for (int i = 1 ; i <= g ; i++) {
        if (cnt[i] == (int)ing.size()) {
            cout << "masterpiece";
            return 0;
        }
    }
    cout << "disaster";
}