#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxN = 1e5 + 5;
int h, k, v, s;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> h >> k >> v >> s;
    int total = 0;
    while (h > 0) {
        v += s;
        v -= max(1ll, (v / 10));
        if (v >= k) h++;
        else {
            h--;
            if (h == 0) v = 0;
        }
        if (v <= 0) {
            h = 0; v = 0;
        }
        total += v;
        if (s > 0) s--;
    }
    cout << total;
}