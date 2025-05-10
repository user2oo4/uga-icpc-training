#include <bits/stdc++.h>
using namespace std;
// #define int long long
typedef pair<int, int> ii;

const int maxN = 5005;
int n, m;
vector<int> AdjList[maxN][26];
vector<int> AdjRev[maxN][26];

bool dist[maxN][maxN];
int ans = 0;

void bfs() {
    queue<ii> q;
    for (int i = 1 ; i <= n ; i++) {
        dist[i][i] = 1;
        q.push(ii(i, i));
        for (int c = 0 ; c < 26 ; c++) {
            for (int v: AdjList[i][c]) {
                if (!dist[i][v]) {
                    dist[i][v] = 1;
                    q.push(ii(i, v));
                }
            }
        }
    }
    while (!q.empty()) {
        ii tmp = q.front();
        int u = tmp.first;
        int v = tmp.second;
        q.pop();
        if (u != v) ans++;
        for (int c = 0 ; c < 26 ; c++) {
            for (int u1: AdjRev[u][c]) {
                for (int v1: AdjList[v][c]) {
                    if (!dist[u1][v1]) {
                        dist[u1][v1] = 1;
                        q.push(ii(u1, v1));
                    }
                }
            }
        }
    }
}

int u, v;
char c;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        cin >> u >> v >> c;
        AdjList[u][c - 'a'].push_back(v);
        AdjRev[v][c - 'a'].push_back(u);
    }
    bfs();
    cout << ans;
}