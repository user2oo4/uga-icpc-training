#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int maxN = 1005;
vector<int> AdjList[maxN][12];
int infect[maxN]; 
// latest day meeting someone (can only be infected on either that day or the day before)
bool quarantine[maxN];
int dist[maxN][12];

int n, k, c;

void bfs(int s) {
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= k + 1 ; j++) {
            dist[i][j] = 0;
        }
    }
    queue<ii> q;
    dist[s][1] = 1;
    q.push(ii(s, 1));
    while (!q.empty()) {
        int u = q.front().first;
        int d = q.front().second;
        q.pop();
        // cout << "dist " << u << " = " << d << endl;
        for (int v: AdjList[u][d]) {
            if (!dist[v][d + 1] && infect[v] <= d + 1) {
                dist[v][d + 1] = 1;
                q.push(ii(v, d + 1));
            }
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        if (dist[i][k + 1]) quarantine[i] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> k >> c;

    for (int i = 0; i < c; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        AdjList[a][d].push_back(b);
        AdjList[b][d].push_back(a);
        infect[a] = max(infect[a], d);
        infect[b] = max(infect[b], d);
    }

    for (int i = 1 ; i <= n ; i++) {
        if (infect[i] == 1) bfs(i);
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) ans += quarantine[i];

    cout << ans << endl;
    for (int i = 1 ; i <= n ; i++) {
        if (quarantine[i]) cout << i << endl;
    }

}