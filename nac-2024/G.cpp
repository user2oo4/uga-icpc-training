#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const int maxN = 105;
ld dp[maxN][maxN];
int r, c;
ld p;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cout << fixed << setprecision(9);
    cin >> r >> c >> p;
    for (int i = 1 ; i <= r ; i++) {
        dp[i][1] = p / 4 * (i - 1);
    }
    for (int i = 1 ; i <= c ; i++) {
        dp[1][i] = p / 4 * (i - 1);
    }
    for (int i = 2 ; i <= r ; i++) {
        for (int j = 2 ; j <= c ; j++) {
            ld a = dp[i - 1][j];
            ld b = dp[i][j - 1];
            if (a > b) swap(a, b);
            ld diff = min(b - a, p);
            dp[i][j] = 0.5 * a + 0.5 * (((p - diff) / p * b) + diff / p * (diff / 2 + a));
        }
    }
    cout << dp[r][c];
}