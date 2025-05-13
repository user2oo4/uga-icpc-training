#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int maxN = 2e5 + 5;
string s[maxN];
string sum[maxN];
string t;
int n;

void proc(int id) {
    int len = s[id].length();
    string cur_string = "";
    int cur_id = 0;
    for (int i = 0 ; i < len ; i++) {
        if (s[id][i] == t[cur_id]) {
            sum[cur_id] += cur_string;
            // cout << "sum " << cur_id << " += " << cur_string << endl;
            cur_string = "";
            cur_id++;
        }
        else cur_string += s[id][i];
        if (cur_id == t.length()) {
            cout << "NO" << endl;
            exit(0);
        }
    }
    sum[cur_id] += cur_string;
    // cout << "sum " << cur_id << " += " << cur_string << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> s[i];
    }
    cin >> t;
    for (int i = 1 ; i <= n ; i++) {
        proc(i);
    }
    cout << "YES" << endl;
    for (int i = 0 ; i < t.length() ; i++) {
        cout << sum[i];
        if (i < t.length() - 1) cout << t[i];
    }
}