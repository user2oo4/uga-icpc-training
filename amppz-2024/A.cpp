#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int maxN = 202;
string s[maxN];
int st[26];
int n;

void solve(int i) {
    vector<int> ans;
    for (int j = 0 ; j < s[i].length() ; j++) {
        int c = s[i][j] - 'A';
        if (!st[c]) return;
        ans.push_back(st[c]);
    }
    cout << (int)ans.size() << endl;
    for (int u: ans) {
        cout << s[u] << ' ';
    }
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> s[i];
        int c = s[i][0] - 'A';
        if (!st[c]) st[c] = i;
    }
    for (int i = 1 ; i <= n ; i++) {
        solve(i);
    }
    cout << -1;
}