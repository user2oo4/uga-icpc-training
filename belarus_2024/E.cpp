#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;

const int maxN = 1e5 + 5;
int n;

vector<int> ans;
int a[maxN];
int cnt[maxN];
vector<int> AdjList[maxN];

void write_ans(int s = 1, int p = -1) {
    ans.push_back(s);
    for (int u: AdjList[s]) {
        if (u == p) continue;
        write_ans(u, s);
        ans.push_back(s);
        for (int i = 1 ; i < cnt[u] ; i++) {
            ans.push_back(u);
            ans.push_back(s);
        }
    }
}

void dfs(int s = 1, int p = -1) {
    for (int u: AdjList[s]) {
        if (u == p) continue;
        dfs(u, s);
    }
    // remaining: a[u]
    for (int u: AdjList[s]) {
        if (u == p) continue;
        if (!a[u]) {
            cout << 0;
            exit(0);
        }
        cnt[u] = a[u];
        if (cnt[u] < 1) {
            cout << 0;
            exit(0);
        }
        a[u] -= cnt[u];
        a[s] -= cnt[u];
    }
    if (a[s] < 0) {
        cout << 0;
        exit(0);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    for (int i = 1 ; i < n ; i++) {
        int u, v;
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    dfs();
    if (a[1]) {
        cout << 0;
        exit(0);
    }
    write_ans();
    for (int u: ans) cout << u << " ";
    cout << endl;
}