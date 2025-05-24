#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
// #define int long long

const int maxN = 11;
string s[11];
int pt[11][11];
bool vis[11][11];
int pts;
int n;
priority_queue<iii> pq;

bool ok(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

char get_adj(char c) {
    if (c == 'o' || c == 'O') return 'O';
    if (c == 'p' || c == 'P') return 'M';
    if (c == 'm' || c == 'M') return 'P';
    return 'x';
}

int get_points(int i, int j) {
    char c = get_adj(s[i][j]);
    int ans = 0;
    for (int di = -1 ; di <= 1 ; di++) {
        for (int dj = -1 ; dj <= 1 ; dj++) {
            if (!di && !dj) continue;
            if (ok(i + di, j + dj) && s[i + di][j + dj] == c) ans++;
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> s[i];
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (s[i][j] == '.') continue;
            pt[i][j] = get_points(i, j);
            if (s[i][j] >= 'A' && s[i][j] <= 'Z') {
                pts += pt[i][j];
                pts += 2;
            }
            else {
                // cout << "pt " << i << " " << j << " = " << pt[i][j] << endl;
                pq.push(iii(pt[i][j], ii(i, j)));
            }
        }
    }
    pts /= 2;
    cout << pts << " ";
    while (!pq.empty()) {
        iii tmp = pq.top();
        pq.pop();
        int p = tmp.first;
        int i = tmp.second.first;
        int j = tmp.second.second;
        // cout << "p i j " << p << " " << i << " " << j << endl;
        if (vis[i][j]) continue;
        vis[i][j] = 1;
        if (!p) break;
        pts += (p + 1);
        s[i][j] += ('A' - 'a');
        for (int di = -1 ; di <= 1 ; di++) {
            for (int dj = -1 ; dj <= 1 ; dj++) {
                if (!di && !dj) continue;
                if (ok(i + di, j + dj) 
                && s[i + di][j + dj] >= 'a' && s[i + di][j + dj] <= 'z'
                && get_adj(s[i + di][j + dj]) == s[i][j]) {
                    pt[i + di][j + dj]++;
                    pq.push(iii(pt[i + di][j + dj], ii(i + di, j + dj)));
                } 
            }
        }
    }
    cout << pts << endl;
    for (int i = 0 ; i < n ; i++) {
        cout << s[i] << endl;
    }
}