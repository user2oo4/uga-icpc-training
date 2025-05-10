#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int maxN = 1e5 + 5;

bool on[maxN][7];
bool ok[maxN][7];
int cur_on[maxN];
int n;
int mask[10] = {119, 96, 62, 124, 105, 93, 95, 100, 127, 125};

bool check(int i, int num)  {
    // check if the LEDs at position i can potentially display num
    // cout << "cur_in " << i << " = " << cur_on[i] << endl;
    // cout << "mask " << num << " = " <<  mask[num] << endl;
    if ((cur_on[i] & mask[num]) != cur_on[i]) return false;
    int rem_mask = mask[num] ^ cur_on[i];
    // cout << "rem mask = " << rem_mask << endl;
    for (int j = 0 ; j < 7 ; j++) {
        if (rem_mask & (1 << j)) {
            if (ok[i][j]) return false;
        }
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j < 7 ; j++) {
            char c;
            cin >> c;
            if (c == 'G') {
                on[i][j] = 1;
                ok[i][j] = 1;
                cur_on[i] += (1 << j);
            } else if (c == 'g') {
                on[i][j] = 0;
                ok[i][j] = 1;
            } else {
                ok[i][j] = 0;
            }
        }
        // cout << cur_on[i] << endl;
    }
    for (int i = 1 ; i <= n ; i++) {
        int x = -1;
        for (int j = 0 ; j < 10 ; j++) {
            if (check(i, j)) {
                if (x == -1) x = j;
                else {
                    x = 10;
                    break;
                }
            }
        }
        if (x == 10) cout << '*';
        else cout << x;
    }
}