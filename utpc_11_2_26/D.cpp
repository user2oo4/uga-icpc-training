#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 2e5 + 5;
const int inf = 1e18;
int a[maxN];
int p[maxN];
int n, k;

int cnt(int diff) {
    // cnt pairs |pi-pj| <= diff
    int r = 1;
    int ans = 0;
    for (int l = 1 ; l <= n ; l++) {
        r = max(r, l);
        while (r + 1 <= n && p[r + 1] - p[l] <= diff) r++;
        ans += (r - l);
        // cout << "l r " << l << " " << r << endl;
    }
    // cout << "cnt " << diff << " = " << ans << endl;
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        p[i] = a[i];
    }
    sort(p + 1, p + 1 + n);
    int l = 0;
    int r = p[n] - p[1];
    while (l < r) {
        int mid = (l + r) / 2;
        if (cnt(mid) < k) l = mid + 1;
        else r = mid;
    }
    // diff is l
    // cout << "diff = " << l << endl;
    int val_l = 0, val_r = 0;
    for (int i = 1 ; i <= n ; i++) {
        int j = lower_bound(p + 1 + i, p + 1 + n, p[i] + l) - p;
        if (j <= n && p[j] - p[i] == l) {
            val_l = p[i];
            val_r = p[j];
            break;
        }
    }
    // cout << "val_l val_r = " << val_l << " " << val_r << endl;
    int ans_l = 0, ans_r = 0;
    for (int i = 1 ; i <= n ; i++) {
        if(a[i] == val_l || a[i] == val_r) {
            if (ans_l == 0) ans_l = i;
            else if (ans_r == 0 && val_l + val_r - a[i] == a[ans_l]) ans_r = i;
        }
    }
    cout << ans_l << " " << ans_r << endl;
}