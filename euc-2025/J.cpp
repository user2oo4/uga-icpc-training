#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int maxN = 105;
int tc;
int n;
string s;
queue<int> w[2], r[2];
bool used[maxN * 2];
vector<int> s1, s2;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tc;
    while (tc--) {
        cin >> n;
        cin >> s;
        s1.clear(); s2.clear();
        s1.push_back(-1); s2.push_back(-1);
        int cnt_w0 = 0;
        int cnt_r1 = 0;
        for (int i = 0 ; i < 2 ; i++) {
            while (!w[i].empty()) w[i].pop();
            while (!r[i].empty()) r[i].pop();
        }
        for (int i = 0 ; i < n ; i++) {
            if (s[i] == 'W') cnt_w0++, w[0].push(i);
            else r[0].push(i);
            used[i] = false;
        }
        if (cnt_w0 & 1) {
            cout << "NO" << endl;
            continue;
        }
        int c0 = 0;
        for (int i = 0 ; i < n ; i++) {
            if (s[i] == 'W') {
                if (c0 < cnt_w0 / 2) w[0].pop();
                c0++;
            }
        }
        for (int i = n ; i < 2 * n ; i++) {
            if (s[i] == 'W') w[1].push(i);
            else cnt_r1++, r[1].push(i);
            used[i] = false;
        }
        if (cnt_r1 & 1) {
            cout << "NO" << endl;
            continue;
        }
        int c1 = 0;
        for (int i = n ; i < 2 * n ; i++) {
            if (s[i] == 'R') {
                if (c1 < cnt_r1 / 2) r[1].pop();
                c1++;
            }
        }
        bool ok = true;
        for (int i = 0 ; i < 2 * n ; i++) {
            // cout << "i = " << i << endl;
            if (used[i]) continue;
            if (s[i] == 'W') {
                if (i >= n) {
                    ok = false;
                    break;
                }
                if (w[0].empty()) {
                    ok = false;
                    break;
                }
                int j = w[0].front();
                // cout << "i j " << i << " " << j << endl;
                w[0].pop();
                s1.push_back(i);
                if (s2.back() > j) {
                    ok = false;
                    break;
                }
                used[j] = true;
                s2.push_back(j);
            } else {
                if (i < n) {
                    r[0].pop();
                    if (w[1].empty()) {
                        ok = false;
                        break;
                    }
                    int j = w[1].front();
                    // cout << "i j " << i << " " << j << endl;
                    w[1].pop();
                    if (s2.back() > j) {
                        ok = false;
                        break;
                    }
                    used[j] = true;
                    s2.push_back(j);
                } else {
                    if (r[1].empty()) {
                        ok = false;
                        break;
                    }
                    int j = r[1].front();
                    // cout << "i j " << i << " " << j << endl;
                    r[1].pop();
                    if (s2.back() > j) {
                        ok = false;
                        break;
                    }
                    used[j] = true;
                    s2.push_back(j);
                }
            }
        }
        cout << ((ok)? "YES": "NO") << endl;
    }
}