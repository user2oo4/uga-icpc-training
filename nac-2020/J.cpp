#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
// #define int long long

int n;
int m;
int a[11];
int sp[33];
vector<ii> vt;
int ans;

void solve(int i) {
    if (i == m + 1) {
        int res = 0;
        vt.clear();
        for (int i = 1 ; i < n ; i++) {
            if (sp[i]) {
                vt.push_back(ii(st, i));
                st = i;
            }
        }
        vt.push_back(ii(st, n));
        for (ii tmp: vt) {
            res += ((tmp.second - tmp.first) == 1);
        }
        ans = max(ans, res);
    }
    int burger = a[i];
    int st = 0;
    vt.clear();
    for (int i = 1 ; i < n ; i++) {
        if (sp[i]) {
            vt.push_back(ii(st, i));
            st = i;
        }
    }
    vt.push_back(ii(st, n));
    int sz = (int)vt.size();
    for (i = 0) {
        if (r - l == 1) continue;
        for (int k = l + 1 ; k < r ; k++) {
            // pick k
            sp[k] = 
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++) {
        cin >> a[i];
    }
}