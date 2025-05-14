#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int maxN = 2e5 + 5;
const int inf = 1e9 + 7;
int n, p, q, s;
int x[maxN];
int y[maxN];

bool solve(int d) {
    // cout << "d = " << d << endl;
    multiset<int> ms;
    for (int i = 1 ; i <= q ; i++) {
        ms.insert(y[i]);
    }
    int cur = 0;
    for (int i = p ; i >= 1 ; i--) {
        // cout << "x " << i << " = " << x[i] << endl;
        int r = min(x[i] + d, s - x[i]);
        auto it = ms.upper_bound(r);
        if (it == ms.begin()) continue;
        it--;
        // cout << "(*it) = " << (*it) << endl;
        if ((*it) >= x[i] - d) {
            cur++;
            ms.erase(it);
        }
    }
    return cur >= n;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> p >> q >> s;
    for (int i = 1 ; i <= p ; i++) {
        cin >> x[i];
    }
    for (int i = 1 ; i <= q ; i++) {
        cin >> y[i];
    }
    sort(x + 1, x + 1 + p);
    int l = 0;
    int r = inf;
    while (l < r) {
        // cout << "l r " << l << " " << r << endl;
        int mid = (l + r) / 2;
        if (solve(mid)) r = mid;
        else l = mid + 1;
    }
    if (r == inf) cout << -1;
    else cout << r;
}