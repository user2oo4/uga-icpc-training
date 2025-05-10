#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) {
    return rng() % (r - l + 1) + l;
}

const int maxN = 2000 + 5;
const int inf = 1e9;
int r, c;
int a[maxN][maxN];
int row[maxN];
int col[maxN]; // number of '.' on rows and columns

int A(int n, int k) {
    if (n < k) return 0;
    int ans = 1;
    for (int i = n ; i >= n - k + 1 ; i--) ans *= i;
    return ans;
}

int calc_rrr_ccc() {
    int ans = 0;
    for (int i = 1 ; i <= r ; i++) {
        ans += A(row[i], 4);
    }
    for (int i = 1 ; i <= c ; i++) {
        ans += A(col[i], 4);
    }
    return ans;
}

int calc_rcr_crc() {
    int ans = 0;
    int sum = 0;
    for (int c1 = 1 ; c1 <= c ; c1++) {
        // fix col for 2 and 3
        sum = 0;
        for (int r1 = 1 ; r1 <= r ; r1++) {
            if (!a[r1][c1]) continue;
            if (row[r1] < 2) continue;
            sum += (row[r1] - 1);
            ans -= (row[r1] - 1) * (row[r1] - 1);
            // cout << "sum = " << sum << endl;
            // cout << "ans = " << ans << endl;
        }
        ans += sum * sum;
    }
    for (int r1 = 1 ; r1 <= r ; r1++) {
        // fix row for 2 and 3
        sum = 0;
        for (int c1 = 1 ; c1 <= c ; c1++) {
            if (!a[r1][c1]) continue;
            if (col[c1] < 2) continue;
            sum += (col[c1] - 1);
            ans -= (col[c1] - 1) * (col[c1] - 1);
        }
        ans += sum * sum;
    }
    return ans;
}

int calc_rcc_crr_rrc_crr() {
    // fix number 2 or 3
    int ans = 0;
    for (int r1 = 1 ; r1 <= r ; r1++) {
        for (int c1 = 1 ; c1 <= c ; c1++) {
            if (!a[r1][c1]) continue;
            ans += (row[r1] - 1) * A(col[c1] - 1, 2);
            ans += (col[c1] - 1) * A(row[r1] - 1, 2);
        }
    }
    return ans * 2;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> r >> c;
    for (int i = 1 ; i <= r ; i++) {
        string s;
        cin >> s;
        for (int j = 1 ; j <= c ; j++) {
            a[i][j] = (s[j - 1] == '.'); // 1: empty, 0: blocked
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
    }
    int ans = 0;
    ans += calc_rrr_ccc();
    ans += calc_rcr_crc();
    ans += calc_rcc_crr_rrc_crr();
    cout << ans;
}