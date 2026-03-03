#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 2e5 + 5;

int a[maxN];
int pos[maxN];
int fr[maxN];
int bc[maxN];
int n;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int l = pos[0];
    int r = pos[0];
    int sum = 0;
    for (int i = 0 ; i < n ; i++) {
        l = min(l, pos[i]);
        r = max(r, pos[i]);
        sum += l * (n - r + 1);
        // cout << "i l r = " << i << " " << l << " " << r << endl;
        // cout << "sum = " << sum << endl;
        if (l > 1) fr[l - 1] -= (n - r + 1);
        if (r < n) bc[r + 1] -= l;
    }
    for (int t = 0 ; t < 2 ; t++) {
        for (int i = n ; i >= 1 ; i--) {
            fr[i] += fr[i + 1];
        }
        for (int i = 1 ; i <= n ; i++) {
            bc[i] += bc[i - 1];
        }    
    }
    for (int i = 1 ; i <= n ; i++) {
        cout << sum + fr[i] + bc[i] << '\n';
    }
}