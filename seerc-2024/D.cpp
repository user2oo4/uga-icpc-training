#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxN = 1e5 + 5;
int a[maxN];
int n;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    int sum = 0;
    int mx = 0;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    if (sum == 0) {
        cout << "Puss in Boots" << endl;
    } else if (sum - mx < n) {
        cout << "Donkey" << endl;
    } else {
        cout << "Puss in Boots" << endl;
    }
}