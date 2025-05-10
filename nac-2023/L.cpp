#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector<int> vt;
int tc, n;

bool solve(vector<int> v) {
    int cntOdd = 0;
    for (int u: v) {
        cntOdd += (u & 1);
    }
    if (cntOdd == n) return 0;
    else if (cntOdd) return 1;
    else {
        if (!(n & 1)) return 1;
        for (int &u: v) {
            u /= 2;
        }
        return solve(v);
    }
} 

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tc;
    while (tc--) {
        vt.clear();
        cin >> n;
        vt.assign(n, 0);
        for (int i = 0 ; i < n ; i++) {
            cin >> vt[i];
        }
        cout << solve(vt) << endl;
    }
}