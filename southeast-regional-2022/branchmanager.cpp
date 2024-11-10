#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int n, m;
vector<int> AdjList[maxN];
int par[maxN];
int in[maxN];
int out[maxN];

int cur_time = 0;

void dfs(int s) {
    in[s] = cur_time++;
    for (int u: AdjList[s]) {
        dfs(u);
    }
    out[s] = cur_time++;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i < n ; i++) {
        int u, v;
        cin >> u >> v;
        par[v] = u;
        AdjList[u].push_back(v);
    }
    for (int i = 1 ; i <= n ; i++) sort(AdjList[i].begin(), AdjList[i].end());
    dfs(1);
    int ans = 0;
    int cur_in, cur_out;
    for (int i = 1 ; i <= m ; i++) {
        int x;
        cin >> x;
        // cout << "in out " << x << " = " << in[x] << " " << out[x] << endl;
        if (i == 1) {
            cur_in = in[x];
            cur_out = out[x];
            ans++;
        } else if (in[x] < cur_in && out[x] < cur_out) {
            cout << ans;
            return 0;
        } else if (in[x] < cur_in) {
            ans++;
        } else {
            cur_in = in[x];
            cur_out = out[x];
            ans++;
        }
        // cout << "cur in out " << cur_in << " " << cur_out << endl;
    }
    cout << ans;
}