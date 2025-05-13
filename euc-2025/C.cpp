#include <bits/stdc++.h>
using namespace std;

int tc, n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        multiset<int> ms;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ms.insert(x);
        }

        int ans = 0;
        while (!ms.empty()) {
            // Take the largest remaining element
            auto it = ms.begin();
            int x = *it;
            ms.erase(it);
            // cout << "x = " << x << endl;
            if (x >= k) {
                ans++;
                continue;
            }
            auto y_it = ms.upper_bound(k - x - 1);
            if (y_it != ms.begin()) {
                --y_it;
                ans++;
                ms.erase(y_it);
                // cout << "(*y_it) = " << (*y_it) << endl;
            } else {
                ans++;
            }
            if (!ms.empty()) {
                auto it = prev(ms.end());
                // cout << "(*it) = " << (*it) << endl;
                ms.erase(it);
            }
        }

        cout << ans - 1 << endl;
    }
}
