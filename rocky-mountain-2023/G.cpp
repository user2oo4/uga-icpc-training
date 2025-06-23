#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5 + 5;
int a[maxN];
bool used[maxN];
int n, r;
int rem;
vector<int> ans;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> r;
    rem = n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    while (rem) {
        int cur_r = 0;
        int last_r = 0;
        int cur_cnt = 0;
        int best_l = 0;
        int best_cnt = 0;
        for (int cur_l = 1 ; cur_l <= n ; cur_l++) {
            while (cur_r < n && a[cur_r + 1] - a[cur_l] <= 2 * r) {
                cur_r++;
                if (!used[cur_r]) last_r = cur_r; 
                cur_cnt += (1 - used[cur_r]);
            }
            // cout << "cur_l cur_r cur_cnt = " << cur_l << " " << cur_r << " " << cur_cnt << endl;
            if (cur_cnt > best_cnt) {
                best_cnt = cur_cnt;
                best_l = a[last_r] - r;
            }
            cur_cnt -= (1 - used[cur_l]);
        }
        rem -= best_cnt;
        ans.push_back(best_l);
        for (int i = 1 ; i <= n ; i++) {
            if (a[i] >= best_l - r && a[i] <= best_l + r) {
                used[i] = 1;
            }
        }
    }
    cout << (int)ans.size() << endl;
    for (int u: ans) cout << u << " ";
}  