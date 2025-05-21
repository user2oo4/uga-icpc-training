#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int maxN = 5000 + 5;
int n, x, y, xl, xh, yl, yh;
bitset<maxN> dp[maxN], pre[maxN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> x >> y;
    int ans = 0;
    pre[0][0] = 1;
    for (int i = 1 ; i <= n ; i++) {
        cin >> xl >> xh >> yl >> yh;
        xl -= x;
        xh -= x;
        yl -= y;
        yh -= y;
        xl = max(xl, 0);
        xh = min(xh, n);
        yl = max(yl, 0);
        yh = min(yh, n);
        for (int cx = 0 ; cx < i ; cx++) {
            dp[cx] |= pre[cx];
            if (cx >= xl && cx <= xh) {
                dp[cx + 1] |= pre[cx];
                dp[cx] |= (pre[cx] >> 1);
            }
        }
    }
    cout << ans;
}