#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ld, ld> pld;

const int maxN = 2e5 + 5;

int x[maxN], y[maxN], v[maxN];
int n;


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> x[i] >> y[i] >> v[i];
        x[i] = x[i] + y[i];
        y[i] = x[i] - 2 * y[i];
    }
    ld l = 0;
    ld r = 2e6;
    int it = 100;
    while (it--) {
        ld mid = (l + r) / 2.0;
        ld min_x = 1e9;
        ld max_x = -1e9;
        ld min_y = 1e9;
        ld max_y = -1e9;
        for (int i = 0 ; i < n ; i++) {
            min_x = min(min_x, x[i] + v[i] * mid);
            max_x = max(max_x, x[i] - v[i] * mid);
            min_y = min(min_y, y[i] + v[i] * mid);
            max_y = max(max_y, y[i] - v[i] * mid);
        }
        if (max_x <= min_x && max_y <= min_y) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(10) << l;
}