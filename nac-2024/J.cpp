#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxN = 1e5 + 5;
int n, p;
int a[maxN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> p;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 1 ; i <= n ; i++) {
        int rem = p - sum;
        if (rem < 0) {
            cout << i - 1;
            return 0;
        }
        if (rem / i < a[i] - 1) {
            cout << i - 1;
            return 0;
        }
        if (rem / i == a[i] - 1 && rem % i == 0) {
            cout << i - 1;
            return 0;
        }
        sum += a[i];
    }
    cout << n;
}