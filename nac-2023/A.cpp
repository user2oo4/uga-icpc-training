#include <bits/stdc++.h>
using namespace std;
#define int long long

int tc;
int n;
int d;

bool ok(int k) {
    // x regions
    int cur = 1; // current compounds
    for (int i = 0 ; i < k ; i++) {
        if (cur > n / (d + 1)) return true;
        cur *= (d + 1);
    }
    return cur >= n;
}

void solve(int n, int d) {
    int l = 0;
    int r = 60;
    while (l < r) {
        int mid = (l + r) / 2;
        if (ok(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tc;
    while (tc--) {
        cin >> n >> d;
        // cout << "n d " << n << " " << d << endl;
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        solve(n, d);
    }
}