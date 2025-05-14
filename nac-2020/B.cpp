#include <bits/stdc++.h>
using namespace std;
// #define int long long

int n, k;
int ship[6][6];
int og[6][6];
int a[6];
int ans;
bool ok(int i, int j) {
    return i >= 1 && i <= n && j >= 1 && j <= n && (ship[i][j] == 0 || ship[i][j] == k + 1);
}

bool check(int id, int i, int j, int dir) {
    // ship size a[id]
    // from i, j. dir = 0 -> right, dir = 1 -> down
    int len = a[id];
    if (!dir) {
        for (int cj = j ; cj <= j + len - 1 ; cj++) {
            if (!ok(i, cj)) return false;
        }
        return true;
    } else {
        for (int ci = i ; ci <= i + len - 1 ; ci++) {
            if (!ok(ci, j)) return false;
        }
        return true;
    }
}

void solve(int id) {
    if (id == k + 1) {
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                if (ship[i][j] == k + 1) return;
            }
        }
        ans++;
        return;
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            for (int dir = 0 ; dir < 1 + (a[id] != 1) ; dir++) {
                if (!check(id, i, j, dir)) continue;
                if (!dir) {
                    for (int cj = j ; cj <= j + a[id] - 1 ; cj++) {
                        ship[i][cj] = id;
                    }
                } else {
                    for (int ci = i ; ci <= i + a[id] - 1 ; ci++) {
                        ship[ci][j] = id;
                    }
                }
                solve(id + 1);
                if (!dir) {
                    for (int cj = j ; cj <= j + a[id] - 1 ; cj++) {
                        ship[i][cj] = og[i][cj];
                    }
                } else {
                    for (int ci = i ; ci <= i + a[id] - 1 ; ci++) {
                        ship[ci][j] = og[ci][j];
                    }
                }
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            char c;
            cin >> c;
            if (c == 'X') ship[i][j] = -1;
            else if (c == '.') ship[i][j] = 0;
            else if (c == 'O') ship[i][j] = k + 1;
            og[i][j] = ship[i][j];
        }
    }
    for (int i = 1 ; i <= k ; i++) {
        cin >> a[i];
    }
    solve(1);
    cout << ans;
}