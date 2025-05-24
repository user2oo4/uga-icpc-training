#include <bits/stdc++.h>
using namespace std;
// #define int long long

int tc;
int a[2][2];

void solve() {
    if (a[0][1] - a[0][0] != 1) {
        cout << -1 << endl;
        return;
    }
    if (a[1][1] - a[1][0] != 1) {
        cout << -1 << endl;
        return;
    }
    int w = a[1][0] - a[0][0];
    if (w < 2) {
        cout << -1 << endl;
        return;
    }
    if (a[1][0] % w == 0) {
        cout << -1 << endl;
        return;
    }
    cout << 100000 << " " << w << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tc;
    while (tc--) {
        cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
        solve();
    }
}