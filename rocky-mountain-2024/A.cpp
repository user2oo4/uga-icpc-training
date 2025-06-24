#include <bits/stdc++.h>
using namespace std;

int n;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int mn = 1000000;
    int mx = 0;
    for (int i = 1 ; i <= n ; i++) {
        int a;
        cin >> a;
        mn = min(mn, a);
        mx = max(mx, a);
    }
    cout << max(0, mn - mx / 2);
}