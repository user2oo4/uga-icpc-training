#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int maxN = 3e4 + 4;
int cnt[maxN];
int a[maxN];
int n, l, r;
int ans_min, ans_max;
void solve(int k) {
    int cur_sum = 0;
    for (int i = 0 ; i < k ; i++) {
        cnt[i] = 0;
    }
    for (int i = 0 ; i < n + k - 1 ; i++) {
        if (i < n) cur_sum += a[i];
        if (i >= k) cur_sum -= a[i - k];
        if (cur_sum > 0) {
            cnt[i % k]++;
        }
    }
    for (int i = 0 ; i < k ; i++) {
        ans_min = min(ans_min, cnt[i]);
        ans_max = max(ans_max, cnt[i]);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> l >> r;
    ans_min = n + 1;
    ans_max = 0;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    for (int i = l ; i <= r ; i++) {
        solve(i);
    }
    cout << ans_min << ' ' << ans_max << endl;
}