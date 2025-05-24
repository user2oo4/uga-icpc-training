#include <bits/stdc++.h>
using namespace std;
const int maxN = 66;

int tc;
int h[maxN][maxN];
int n;

vector<int> ans;

void solve() {
    ans.clear();
    for (int i = 1 ; i <= n ; i++) {
        if (i & 1) {
            for (int j = 1 ; j <= n ; j++) {
                ans.push_back(h[i][j]);
            }
        } else for (int j = n ; j >= 1 ; j--) {
            ans.push_back(h[i][j]);
        }
    }
    int up = 0;
    int dwn = 0;
    for (int i = 1 ; i < n * n ; i++) {
        if (ans[i] > ans[i - 1]) up++;
        else dwn++;
    }
    if (up > dwn) reverse(ans.begin(), ans.end());
    for (int u: ans) cout << u << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                cin >> h[i][j];
            }
        }
        solve();
    }
}