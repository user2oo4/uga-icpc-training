#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;
vector<vector<int>> a;
int tc, n, m;

vector<int> vt1;
vector<int> vt2;
int get_count(int j) {
    int ans = 0;
    vt1.clear(); vt2.clear();
    for (int i = 1 ; i <= n ; i++) {
        vt1.push_back(a[i][j]);
        vt2.push_back(a[i][j + 1]);
    }
    sort(vt2.begin(), vt2.end());
    sort(vt1.begin(), vt1.end());
    // cout << "vt1: ";
    // for (int u: vt1) cout << u << " ";
    // cout << endl;
    // cout << "vt2: ";
    // for (int u: vt2) cout << u << " ";
    // cout << endl;
    int i1 = 0;
    for (int i2 = 0 ; i2 < n ; i2++) {
        while (i1 < n - 1 && vt2[i2] >= vt1[i1]) i1++;
        if (i1 < n && vt2[i2] < vt1[i1]) {
            // cout << "vt2 " << i2 << " = " << vt2[i2] << endl;
            // cout << "vt1 " << i1 << " = " << vt1[i1] << endl;
            ans++; i1++;
        }
    }
    // cout << "ans = " << ans << endl;
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        a.assign(n + 1, vector<int>(m + 1, 0));
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                cin >> a[i][j];
            }
        }
        int res = 0;
        for (int j = 1 ; j < m ; j++) {
            res += get_count(j);
            if (res >= n) break;
        }
        if (res >= n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}