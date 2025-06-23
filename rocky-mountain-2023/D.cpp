#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

char c[8];
vector<int> cnt(8, 0);

ld ans[50][128];

ld solve(int left, int mask) {
    // mask: used or not
    if (ans[left][mask] > -0.5) return ans[left][mask];
    if (mask == (1 << 7) - 1) return ans[left][mask] = 1.0;
    ld res = 0.0;
    int new_turn = left;
    cout << "solve " << left << " " << mask << endl;
    for (int i = 1 ; i <= 7 ; i++) {
        if (mask & (1 << (i - 1))) {
            continue;
        } else {
            // cout << "i = " << i << endl;
            // cout << "(1 << (i - 1)) = " << (1 << (i - 1)) << endl;
            // cout << "mask + (1 << (i - 1)) = " << mask + (1 << (i - 1)) << endl;
            res += solve(left - 1, mask + (1 << (i - 1))) * cnt[i] / left;
            new_turn -= cnt[i];
        }
    }
    if (new_turn > 0) res += (1.0 + solve(left - 1, mask)) * new_turn / left;
    cout << "ans " << left << " " << mask << " = " << res << endl;
    return ans[left][mask] = res;
}

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> c + 1;
    for (int i = 0 ; i <= 45 ; i++) {
        for (int j = 0 ; j < (1 << 7) ; j++) {
            ans[i][j] = -1.0;
        }
    }
    for (int i = 1 ; i <= 7 ; i++) {
        cnt[i] += 4;
        if (c[i] == 'A') cnt[1]--;
        else if (c[i] >= '2' && c[i] <= '7') cnt[c[i] - '0']--;
    }
    for (int i = 1 ; i <= 7 ; i++) cout << cnt[i] << " ";
    cout << endl;
    cout << fixed << setprecision(12) << solve(45, 0);
}