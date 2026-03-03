#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 1e5 + 5;
int c[maxN];
int n, k;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int st = 0;
    int en = n + 1;
    for (int i = 1 ; i <= n ; i++) {
        cin >> c[i];
        if (c[i] < k) {
            st = i;
        }
        if (c[i] > k && en == n + 1) {
            en = i;
        }
    }
    // cout << "st en " << st << " " << en << endl;
    int ans = max(0ll, en - st - 1);
    int diff = c[st] + c[en] - 2 * k;
    while (st >= 1 && en <= n) {
        // cout << "st en diff = " << st << " " << en << " " << diff << endl;
        if (diff == 0) {
            ans = en - st + 1;
            st--;
            if (st) diff += (c[st] - k);
        }
        else if (diff < 0) {
            en++;
            if (en <= n) diff += (c[en] - k);
            else break;
        }
        else {
            // diff > 0
            st--;
            if (st) diff += (c[st] - k);
        }
    }
    cout << ans;
}