#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define int long long

const int mod = 998244353;
const int maxN = 3e4 + 5;
string s;
int n;
int dp[maxN];

int mid, l, r;

vector<ii> z_function(string s) {
    int n = s.size();
    vector<ii> z(n, {0, 0});
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i].first = min(r - i, z[i - l].first);
        }

        z[i].second = 1;
        while (i + z[i].first < n) {
            char a = s[z[i].first];
            char b = s[i + z[i].first];

            if (a != '?' && b != '?' && a != b) break;

            if (a == '?' && b == '?') {
                z[i].second *= 26;
                z[i].second %= mod;
            }

            z[i].first++;
        }

        if (i + z[i].first > r) {
            l = i;
            r = i + z[i].first;
        }
    }
    return z;
}

void calc_dp(int len) {
    if (n & 1) {
        mid = (n + 1) / 2;
        l = mid - len / 2;
        r = mid + len / 2;
    }
    else {
        l = n / 2 - len / 2 + 1;
        r = n / 2 + len / 2;
    }
    int rem = n - r;
    string r_side = s.substr(r + 1, rem);
    string l_side = s.substr(1, rem);
    string t = r_side + '#' + l_side; 
    vector<ii> z = z_function(t);
    for (int nxtR = r + 1 ; nxtR <= n ; nxtR++) {
        
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> s;
    n = s.length();
    s = ' ' + s;
    for (int i = (n & 1) ; i <= n ; i += 2) {
        dp[i] = 1;
    }
    for (int i = (n & 1) ; i <= n ; i += 2) {
        calc_dp(i);
    }
}