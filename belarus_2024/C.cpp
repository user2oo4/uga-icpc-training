#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
typedef pair<int, int> ii;

int tc;
int a;
const int BIT = 32;
const int MOD = (1ull << BIT);

vector<int> ans;

int bpow(int a, int b, int mod = MOD) {
    if (!b) return 1;
    __int128 x = bpow(a, b / 2, mod);
    x = x * x % mod;
    if (b & 1) x = x * a % mod;
    return x;
}

int solve(int a) {
    int b = 0;
    for (int i = 1 ; i < BIT ; i++) {
        int cur_a = a & ((1ull << (i + 1)) - 1); // bit i -> bit 0
        int br = bpow(cur_a, b, (1ull << (i + 1)));
        int bit_b = (br & (1ull << i)) ^ (a & (1ull << i));
        if (bit_b) b += (1ull << i);
    }
    // cout << "bpow(a, b) = " << bpow(a, b) << endl;
    // cout << "a ^ b = " << (a ^ b) << endl;
    if (bpow(a, b) == a ^ b) return b;
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while (tc--) {
        ans.clear();
        cin >> a;
        if (a & 1) {
            int x = solve(a);
            if (x) cout << 1 << " " << x << endl;
            else if (a == 1) cout << 1 << " " << 0 << endl;
            else cout << 0 << endl;
        }
        else {
            // a even
            int cur_pw = 1;
            for (int b = 0 ; b <= BIT ; b++) {
                // a
                if (b) cur_pw = cur_pw * a % MOD;
                if ((a ^ b) == cur_pw) ans.push_back(b);
            }
            if (a > BIT) {
                ans.push_back(a);
            }
            cout << ans.size() << " ";
            for (int u: ans) cout << u << " ";
            cout << endl;
        }
    }
}