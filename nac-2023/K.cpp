#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int t1 = -1, s1 = -1, i1 = -1;
int t2 = -1, s2 = -1, i2 = -1;

int find_ans() {
    // cout << "t1 s1 i1 = " << t1 << " " << s1 << " " << i1 << endl;
    // cout << "t2 s2 i2 = " << t2 << " " << s2 << " " << i2 << endl;
    int br = s2 * i1 - i2 * s1;
    int d = t1 * i2 - t2 * i1;
    if (br % d == 0) {
        if (br / d >= 1) return br/d;
    } 
    return -1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    int cur_tab = 0;
    stack<int> st;
    int ans = -1;
    int sp = -1;
    for (int i = 1 ; i <= n ; i++) {
        cin >> s;
        int len = s.length();
        char c = s[len - 1];
        bool open = (c == '{');
        int cntS = 0, cntT = 0;
        for (int i = 0 ; i < len - 1 ; i++) {
            if (s[i] == 's') cntS++;
            if (s[i] == 't') cntT++;
        }
        if (!open) {
            cur_tab = st.top();
            st.pop();
        }
        // cout << "i = " << i << endl;
        // cout << "cur_tab = " << cur_tab << endl;
        // cout << "cntS cntT = " << cntS << " " << cntT << endl;
        if ((!cur_tab) && (cntS || cntT)) {
            cout << -1;
            return 0;
        }
        if (cur_tab) {
            if (t1 == -1) {
                t1 = cntT;
                s1 = cntS;
                i1 = cur_tab;
            } else if (t2 == -1) {
                if (!(t1 * cur_tab == cntT * i1)) {
                    t2 = cntT;
                    s2 = cntS;
                    i2 = cur_tab;
                }
                else {
                    if (s1 == cntS) continue;
                    else {
                        cout << -1;
                        return 0;
                    }
                }
                ans = find_ans();
                sp = (t1 * ans + s1) / i1;
                // cout << "ans = " << ans << endl;
                // cout << "sp = " << sp << endl;
                if (ans == -1) {
                    cout << ans;
                    return 0;
                }
            } else {
                if ((cntT * ans + cntS) != sp * cur_tab) {
                    cout << -1;
                    return 0;
                }
            }
        }

        if (open) {
            st.push(cur_tab);
            cur_tab++;
        }
    }
    if (ans == -1) cout << 1 << endl;
    else cout << ans;
}