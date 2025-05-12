#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int maxN = 1e6 + 5;
int a[maxN];
int n;

int get_ans(int i) {
    int l = i;
    int r = i;
    int ans = 1;
    while (l > 1 && r < n && a[l - 1] == a[r + 1] && a[l - 1] < a[l]) {
        // cout << "l r " << l << " " << r << endl;
        l--; r++; ans++;
    }
    return ans < 2? -1: (ans * 2 - 1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    int ans = -1;
    for (int i = 1 ; i <= n ; i++) {
        ans = max(ans, get_ans(i));
    }
    cout << ans;
}