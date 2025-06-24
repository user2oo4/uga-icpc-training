#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxN = 5e5 + 5;

int x[maxN];
int y[maxN];
int n;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int mx = 0;
    int p = 0;
    for (int i = 1 ; i <= n ; i++) {
        cin >> x[i] >> y[i];
        if (y[i] > mx) {
            p = i;
            mx = y[i];
        }
    }
    // p
    int left = p - 1;
    int ans_l = p - 1;
    for (int i = p - 2 ; i >= 1 ; i--) {
        if ((y[p] - y[i]) * (x[p] - x[left]) <= (x[p] - x[i]) * (y[p] - y[left])) {
            left = i;
            if (y[i] <= y[ans_l]) ans_l = i;
        }
    }
    int right = p + 1;
    int ans_r = p + 1;
    for (int i = p + 2 ; i <= n ; i++) {
        if ((y[p] - y[i]) * (x[right] - x[p]) <= (x[i] - x[p]) * (y[p] - y[right])) {
            right = i;
            if (y[i] <= y[ans_r]) ans_r = i;
        }
    }
    cout << x[ans_l] << " " << y[ans_l] << endl;
    cout << x[ans_r] << " " << y[ans_r];
}