#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int maxN = 1e3 + 5;
vector<int> AdjList[maxN];
int ans[maxN];
int dist[maxN];
int n;

void dfs(int st, int s, int p = -1) {
    if (dist[s] > 1) ans[st]++;
    for (int u: AdjList[s]) {
        if (u == p) continue;
        dist[u] = dist[s] + 1;
        dfs(st, u, s);
    }
}

void get_ans(int st, int s, int p = -1) {
    for (int u: AdjList[s]) {
        if (u == p) continue;
        if (st != s) cout << st << " " << s << " " << u << endl;
        get_ans(st, u, s);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1 ; i < n ; i++) {
        int u, v;
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    int best_ans = n * n;
    int star = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) dist[j] = 0;
        dfs(i, i);
        if (ans[i] < best_ans) {
            best_ans = ans[i];
            star = i;
        }
    }
    cout << best_ans << endl;
    get_ans(star, star);
}