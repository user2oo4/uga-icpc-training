#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 6;
int n;
int a[maxN];
int pos[maxN];
int dp[maxN][2];
int mn[maxN][2]; // min index that still reaches

int get_dist(int i, int j, int dir) {
    // distance from i to j, going left or right
    // right: dir = 0, left: dir = 1
    if (!dir) dir = -1;
    int diff = (pos[i] - pos[j]) * dir;
    if (diff < 0) diff += n;
    return diff;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int d = 0 ; d < 2 ; d++) {
        int cur_min = 1;
        int cur_dist = 0;
        for (int i = 1 ; i <= n ; i++) {
            while (cur_dist >= k) {
                cur_dist -= get_dist(a[cur_min], a[cur_min + 1], d);
                cur_min++;
            }
            mn[i][d] = cur_min;
        }
    }
}