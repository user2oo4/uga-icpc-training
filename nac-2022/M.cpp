#include <bits/stdc++.h>
using namespace std;

const int len = 6;
string cur_str = "aaaaaa";
vector<string> all_str;

void process(int pos = 0, int rev = 1) {
    if (2 * pos + 2 > len) {
        all_str.push_back(cur_str);
        // cout << cur_str << endl;
        return;
    }
    int crev = 1;
    if (cur_str[pos * 2] == 'z') crev = -1;
    process(pos + 1, crev);
    while (cur_str[pos * 2] + rev < (26 + 'a') && cur_str[pos * 2] + rev >= 'a') {
        cur_str[pos * 2 + 1] += rev;
        all_str.push_back(cur_str);
        // cout << cur_str << endl;
        cur_str[pos * 2] += rev;
        crev *= -1;
        process(pos + 1, crev);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    process();
    for (int i = 0 ; i < n ; i++) {
        cout << all_str[i] << endl;
    }
}