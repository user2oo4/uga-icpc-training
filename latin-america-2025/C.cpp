#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int maxN = 1e5 + 5;
int c, n;
int t[maxN];

bool ok(int x) {
    int cur = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (t[i] >= x) cur = 0;
        else cur++;
        if (cur > c) return false;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> c >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> t[i];
    }
    int l = -55;
    int r = 55;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (!ok(mid)) r = mid - 1;
        else l = mid;
    }
    cout << r;
}