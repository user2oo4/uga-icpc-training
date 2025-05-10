#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
// #define int long long

const int maxN = 2e5 + 5;
vector<int> val;
map<int, int> M;
int n;
int k[maxN];
vector<int> a[maxN];
ii pos[maxN];

int dp[maxN * 2];

int ans;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> k[i];
        a[i].assign(k[i] + 1, 0);
        ans += (k[i] > 1)? 2: 1;
        for (int j = 1 ; j <= k[i] ; j++) {
            cin >> a[i][j];
            val.push_back(a[i][j]);
        }
    }
    int sz = (int)val.size();
    for (int i = 0 ; i < (int)val.size() ; i++) {
        M[val[i]] = i + 1;
    }
    for (int i = 1 ; i <= n ; i++) {
        pos[i].first = pos[i].second = M[a[i][1]];
        for (int j = 1 ; j <= k[i] ; j++) {
            a[i][j] = M[a[i][j]];
            pos[i].first = min(pos[i].first, a[i][j]);
            pos[i].second = max(pos[i].second, a[i][j]);
        }
    }
    
}