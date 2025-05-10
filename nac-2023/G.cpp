#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxN = 2e5 + 5;
int a[maxN];
int b[maxN];
int n;
int m;
int k;

vector<int> cur;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    int paid = 0;
    for (int i = 1 ; i <= n + m ; i++) {
        if (i - m > 0) {
            paid -= b[i - m];
        }
        if (i <= n) {
            cur.push_back(i);
        }
        while (paid < k && !cur.empty()) {
            if (cur.back() <= i - m) {
                cur.pop_back();
                continue;
            }
            int i1 = cur.back();
            int x = min(k - paid, a[i1]);
            a[i1] -= x;
            b[i1] += x;
            paid += x;
            ans += x;
            if (!a[i1]) cur.pop_back();
        }
    }

    cout << ans;
}