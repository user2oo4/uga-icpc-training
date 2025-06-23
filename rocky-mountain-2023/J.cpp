#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;
int cnt[maxN];

int n;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        int m;
        cin >> m;
        for (int j = 0 ; j < m ; j++) {
            int l, r;
            cin >> l >> r;
            cnt[l]++;
            cnt[r + 1]--;
        }
    }
    for (int i = 1 ; i < 86400 ; i++) {
        cnt[i] += cnt[i - 1];
    }
    int cur_mx = 0;
    int cur_cnt = 0;
    for (int i = 0 ; i < 86400 ; i++) {
        if (cnt[i] == cur_mx) cur_cnt++;
        else if (cnt[i] > cur_mx) {
            cur_mx = cnt[i];
            cur_cnt = 1;
        }
    }
    cout << cur_mx << endl << cur_cnt;
}  