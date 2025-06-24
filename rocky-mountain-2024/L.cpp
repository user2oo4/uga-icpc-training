#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int a[maxN];
int n;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }
    int cnt = 0;
    int temp = -1;
    for (int i = 0 ; i < maxN ; i++) {
        if (i) a[i] += a[i - 1];
        if (a[i] == n) {
            // cout << i << endl;
            cnt++;
            if (temp == -1) temp = i;
        }
    }
    if (!cnt) {
        cout << "bad news";
    } else cout << cnt << " " << temp;
}