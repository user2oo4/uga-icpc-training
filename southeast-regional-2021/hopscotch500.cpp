#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int maxN = 500 + 5;
const int maxK = 500 * 500 + 5;
const int inf = 1e18;

int n, k;

vector<ii> pos[maxK];
int a[maxN][maxN];
int dist_row[maxN];
int dist_col[maxN];
int dist[maxN][maxN];
bool has_col[maxN][maxK];
bool has_row[maxN][maxK];

void bfs(int x) {
    // cout << "bfs " << x << endl;
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    for (ii tmp: pos[x - 1]) {
        pq.push(iii(dist[tmp.first][tmp.second], tmp));
    }
    while (!pq.empty()) {
        int d = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        // cout << "dist " << row << " " << col << " = " << d << endl;
        pq.pop();
        for (int i = row ; i <= n ; i++) {
            int new_dist = d + (i - row) * (i - row);
            if (new_dist < dist_row[i]) {
                dist_row[i] = new_dist;
            } 
        }
        for (int i = row ; i >= 1 ; i--) {
            int new_dist = d + (i - row) * (i - row);
            if (new_dist < dist_row[i]) {
                dist_row[i] = new_dist;
            } 
        }
        for (int i = col ; i <= n ; i++) {
            int new_dist = d + (i - col) * (i - col);
            if (new_dist < dist_col[i]) {
                dist_col[i] = new_dist;
            }
        }
        for (int i = col ; i >= 1 ; i--) {
            int new_dist = d + (i - col) * (i - col);
            if (new_dist < dist_col[i]) {
                dist_col[i] = new_dist;
            } 
        }
    }
    for (ii tmp: pos[x]) {
        dist[tmp.first][tmp.second] = min(dist_row[tmp.first], dist_col[tmp.second]);
    }
    for (int i = 1 ; i <= n ; i++) {
        if (!has_row[i][x]) dist_row[i] = inf;
        if (!has_col[i][x]) dist_col[i] = inf;
        // cout << "dist row col " << i << " = " << dist_row[i] << " " << dist_col[i] << endl;
    }
}

// void bfs_row(int x) {
//     // from x to x + 1
//     priority_queue<ii, vector<ii>, greater<ii>> pq;
//     for (int i = 1 ; i <= n ; i++) {
//         if (dist_row[i] != inf) pq.push(ii(dist_row[i], i));
//     }
//     while(!pq.empty()) {
//         int d = pq.top().first;
//         int i = pq.top().second;
//         pq.pop();
//         if (dist_row[i] != d) continue;
//         // cout << "dist row " << i << " = " << d << endl;
//         for (int j = i - 1 ; j >= 1 ; j--) {
//             int new_dist = dist_row[i] + (i - j) * (i - j);
//             // cout << "j = " << j << endl;
//             // cout << "new dist " << new_dist << endl;
//             if (dist_row[j] > new_dist) {
//                 dist_row[j] = new_dist;
//                 if (has_row[j][x]) pq.push(ii(dist_row[j], j));
//             } else break;
//         }
//         for (int j = i + 1 ; j <= n ; j++) {
//             int new_dist = dist_row[i] + (i - j) * (i - j);
//             // cout << "j = " << j << endl;
//             // cout << "new dist " << new_dist << endl;
//             if (dist_row[j] > new_dist) {
//                 dist_row[j] = new_dist;
//                 if (has_row[j][x]) pq.push(ii(dist_row[j], j));
//             } else break;
//         }
//     }
//     for (int i = 1 ; i <= n ; i++) {
//         if (!has_row[i][x]) dist_row[i] = inf;
//         // else {
//         //     cout << "dist row " << i << " " << x << " = " << dist_row[i] << endl;
//         // }
//     }
// }

// void bfs_col(int x) {
//     // from x to x + 1
//     priority_queue<ii, vector<ii>, greater<ii>> pq;
//     for (int i = 1 ; i <= n ; i++) {
//         if (dist_col[i] != inf) pq.push(ii(dist_col[i], i));
//     }
//     while(!pq.empty()) {
//         int d = pq.top().first;
//         int i = pq.top().second;
//         pq.pop();
//         if (dist_col[i] != d) continue;
//         for (int j = i - 1 ; j >= 1 ; j--) {
//             int new_dist = dist_col[i] + (i - j) * (i - j);
//             if (dist_col[j] > new_dist) {
//                 dist_col[j] = new_dist;
//                 if (has_col[j][x]) pq.push(ii(dist_col[j], j));
//             } else break;
//         }
//         for (int j = i + 1 ; j <= n ; j++) {
//             int new_dist = dist_col[i] + (i - j) * (i - j);
//             if (dist_col[j] > new_dist) {
//                 dist_col[j] = new_dist;
//                 if (has_col[j][x]) pq.push(ii(dist_col[j], j));
//             } else break;
//         }
//     }
//     for (int i = 1 ; i <= n ; i++) {
//         if (!has_col[i][x]) dist_col[i] = inf;
//         // else {
//         //     cout << "dist col " << i << " " << x << " = " << dist_col[i] << endl;
//         // }
//     }
// }


signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            cin >> a[i][j];
            has_row[i][a[i][j]] = 1;
            has_col[j][a[i][j]] = 1;
            pos[a[i][j]].push_back(ii(i, j));
            dist[i][j] = inf;
            if (a[i][j] == 1) dist[i][j] = 0;
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        if (!has_row[i][1]) dist_row[i] = inf;
        if (!has_col[i][1]) dist_col[i] = inf;
    }
    for (int i = 2 ; i <= k ; i++) {
        bfs(i);
    }
    int ans = inf;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if (a[i][j] == k) {
                ans = min(ans, dist[i][j]);
            }
        }
    }
    if (ans == inf) cout << -1;
    else cout << ans;
}