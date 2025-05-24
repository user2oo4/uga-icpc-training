#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int maxN = 1e5 + 5;
int h, w, q;

string s[8];
bool flip[8][maxN];
bool flip_col[maxN];
int ans[(1 << 8)];

int get_ans() {
    int res = ans[0];
    for (int mask = 0 ; mask < (1 << h) ; mask++) {
        // cout << "ans " << mask << " = " << ans[mask] << endl;
        res = min(res, ans[mask] + __builtin_popcount(mask));
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> h >> w >> q;
    vector<vector<vector<int>>> bit((1 << h), vector<vector<int>>(h, vector<int>(w, 0)));
    vector<vector<int>> cnt_col((1 << h), vector<int>(w, 0));
    for (int i = 0 ; i < h ; i++) {
        cin >> s[i];
        for (int j = 0 ; j < w ; j++) {
            bit[0][i][j] = s[i][j] - '0';
        }
    }
    for (int mask = 0 ; mask < (1 << h) ; mask++) {
        for (int i = 0 ; i < h ; i++) {
            for (int j = 0 ; j < w ; j++) {
                bit[mask][i][j] = bit[0][i][j] ^ ((mask >> i) & 1);
                // cout << "bit " << mask << " " << i << " " << j << " = " << bit[mask][i][j] << endl;
                cnt_col[mask][j] += bit[mask][i][j];
            }
        }
        for (int j = 0 ; j < w ; j++) {
            // cout << "col " << mask << " " << j << " = " << cnt_col[mask][j] << endl;
            ans[mask] += min(cnt_col[mask][j], 1 + (h - cnt_col[mask][j]));
        }
        // cout << "ans " << mask << " = " << ans[mask] << endl;
    }
    cout << get_ans() << endl;
    while (q--) {
        char t;
        int i, j;
        cin >> t;
        if (t == 'R') {
            // flip row
            cin >> i;
            i--;
            for (int mask = 0 ; mask < (1 << h) ; mask++) {
                if (mask & (1 << i)) continue;
                int nmask = mask ^ (1 << i);
                swap(ans[mask], ans[nmask]);
                swap(cnt_col[mask], cnt_col[nmask]);
                swap(bit[mask], bit[nmask]);
            }
        } else if (t == 'K') {
            // flip column
            cin >> j;
            j--;
            flip_col[j] ^= 1;
            for (int mask = 0 ; mask < (1 << h) ; mask++) {
                ans[mask] -= min(cnt_col[mask][j], 1 + (h - cnt_col[mask][j]));
                cnt_col[mask][j] = h - cnt_col[mask][j];
                ans[mask] += min(cnt_col[mask][j], 1 + (h - cnt_col[mask][j]));
            }
        } else {
            // flip square
            cin >> i >> j;
            i--; j--;
            flip[i][j] ^= 1;
            for (int mask = 0 ; mask < (1 << h) ; mask++) {
                // if (mask == 7) cout << bit[0][i][j] << " " << flip_col[j] << " " << flip[i][j] << endl;
                int change = 1;
                int b = bit[0][i][j] ^ ((mask >> i) & 1) ^ flip_col[j] ^ flip[i][j];
                // if (mask == 7) cout << "b = " << b << endl;
                // if (mask == 7) cout << "cnt_col " << j << " = " << cnt_col[mask][j] << endl;
                if (!b) change = -1;
                ans[mask] -= min(cnt_col[mask][j], 1 + (h - cnt_col[mask][j]));
                cnt_col[mask][j] += change;
                // if (mask == 7) cout << "cnt_col " << j << " = " << cnt_col[mask][j] << endl;
                ans[mask] += min(cnt_col[mask][j], 1 + (h - cnt_col[mask][j]));
            }
        }
        cout << get_ans() << endl;
    }
}