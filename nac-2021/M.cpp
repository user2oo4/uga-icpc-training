#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
// #define int long long

const int maxN = 1 << 20;
vector<ii> col[maxN];
int n;

bool check(ii c, ii x, ii y) {
    return c.first == x.first && abs(c.second - x.second) == 1
    && c.second == y.second && abs(c.first - y.first) == 1;
}

bool check_col(int i) {
    if (col[i].size() != 3) return false;
    if (check(col[i][0], col[i][1], col[i][2])) return true;
    if (check(col[i][0], col[i][2], col[i][1])) return true;
    if (check(col[i][1], col[i][0], col[i][2])) return true;
    if (check(col[i][1], col[i][2], col[i][0])) return true;
    if (check(col[i][2], col[i][0], col[i][1])) return true;
    if (check(col[i][2], col[i][1], col[i][0])) return true;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    int colors = ((1 << (2 * n)) - 1) / 3;
    bool ok = true;
    for (int i = 1 ; i <= (1 << n) ; i++) {
        for (int j = 1 ; j <= (1 << n) ; j++) {
            int x;
            cin >> x;
            if (x > colors) ok = false;
            col[x].push_back(ii(i, j));
        }
    }
    if (!ok) {
        cout << 0;
        return 0;
    }
    if (col[0].size() != 1) {
        cout << 0;
        return 0;
    }
    for (int i = 1 ; i <= colors ; i++) {
        if (!check_col(i)) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}