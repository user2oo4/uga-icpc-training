#include <bits/stdc++.h>
using namespace std;

#define int long long

set<int> S;
vector<int> vt[64];
int n;
int c;

void proc(int x) {
    int d = 1;
    int i = 0;
    // cout << "proc " << x << endl;
    while (true) {
        int r = x % d;
        int q = x / d;
        if ((q + (r != 0)) <= c) vt[i].push_back(q + (r != 0));
        // cout << "ans = " << q + (r != 0) << endl;
        if (q + (r != 0) == 1) break;
        i++; 
        d *= 2;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> c;
    for (int i = 1 ; i <= n ; i++) {
        int x;
        cin >> x;
        if (x == c || x == 1) {
            cout << "YES";
            return 0;
        }
        proc(x);
    }
    vector<int> cur = vt[0];
    sort(cur.begin(), cur.end());
    for (int i = 1 ; i < 64 ; i++) {
        vector<int> ncur;
        vector<bool> vis(c + 1, false);
        sort(vt[i].begin(), vt[i].end());
        // cout << "vt " << i << " = " << endl;
        // for (int v: vt[i]) cout << v << " ";
        // cout << endl;
        if (vt[i].empty()) {
            cout << "NO";
            return 0;
        }
        if (vt[i][0] == 1 && !cur.empty()) {
            cout << "YES";
            return 0;
        } 
        for (int u: cur) {
            for (int v: vt[i]) {
                if (u + v <= c && !vis[u + v]) {
                    vis[u + v] = 1;
                    if (u + v == c) {
                        cout << "YES";
                        return 0;
                    }
                    ncur.push_back(u + v);
                }
            }
        }
        if (ncur.empty()) break;
        cur = ncur;
    }
    cout << "NO";
}