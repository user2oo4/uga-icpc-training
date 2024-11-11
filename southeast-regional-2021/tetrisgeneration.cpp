#include <bits/stdc++.h>
using namespace std;
#define int long long

int tc;
int n;
const int maxN = 1000 + 5;
string s;

int cnt[7];
map<char, int> M;
bool ck_valid(int st, int en) {
    // cout << "ck_valid " << st << " " << en << endl;
    for (int i = 0 ; i < 7 ; i++) {
        cnt[i] = 0;
    }
    for (int j = st ; j <= en ; j++) {
        int id = M[s[j]];
        cnt[id]++;
        if (cnt[id] > 1) return false;
    }
    // cout << "true" << endl;
    return true;
}

signed main() {
    cin >> tc;
    M['J'] = 0;
    M['L'] = 1;
    M['S'] = 2;
    M['Z'] = 3;
    M['I'] = 4;
    M['O'] = 5;
    M['T'] = 6;
    while(tc--) {
        cin >> s;
        n = s.length();
        bool ans = false;
        for (int i = 0 ; i < min(7ll, n) ; i++) {
            // starting at i
            int cur_l = 0;
            int cur_r = i;
            bool ok = true;
            while(cur_l < n) {
                ok &= ck_valid(cur_l, cur_r);
                cur_l = cur_r + 1;
                cur_r = min(n - 1, cur_l + 6);
                if (!ok) break;
            }
            ans |= ok;
        }
        cout << ans << endl;
    }
}