#include <bits/stdc++.h>
using namespace std;

int n, m;
string s1, s2;

bool solve() {
    int j = 0;
    int q = -1;
    for (int i = 0 ; i < n ; i++) {
        if (j < m && s1[i] == s2[j]) {
            j++;
            if (s1[i] == '0') q = j;
        } else if (s1[i] == '0') {
            j = q;
            if (j == -1) return false;
        }
    }
    return j == m;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cin >> s1;
        cin >> s2;
        bool ans = solve();
        cout << (ans? "yes": "no") << endl;
    }
}