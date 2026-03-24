#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxN = 2e5 + 5;
string s;


int n, m;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    cin >> m;
    n = (int)s.length();
    int cur = 0;
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        if (s[i] == 'A') cur++;
        else ans += cur;
    }
    cout << max(0ll, ans - m);
}