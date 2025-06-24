#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 4e5 + 5;

vector<int> a, depth;

int n, d, l;

bool ok() {
    int has = 1;
    vector<int> cnt(n, 0);
    for (int i = 0 ; i < n ; i++) cnt[depth[i]]++;
    for (int i = 0 ; i < n ; i++) {
        if (cnt[i] > has) return false;
        has -= cnt[i];
        has *= 2;
        if (has > n) return true;
    }
    return true;
}

bool check(int x) {
    // ans = x
    if (x < l) return false;
    x -= l;
    for (int i = 0 ; i < n ; i++) {
        depth[i] = (x - a[i]) / d;
        depth[i] = min(depth[i], n - 1);
        if (depth[i] <= 0) return false;
    }
    return ok();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> d >> l;
    a.assign(n, 0); depth.assign(n, 0);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    int lef = 0;
    int rig = (int)1e18;
    while (lef < rig) {
        // cout << "l r " << l << " " << r << endl;
        int mid = (lef + rig) / 2;
        if (check(mid)) rig = mid;
        else lef = mid + 1;
    }
    cout << rig;
}