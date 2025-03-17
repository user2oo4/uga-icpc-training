#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) {
    return rng() % (r - l + 1) + l;
}

const int maxN = 15;
const int inf = 301;
int t[maxN];

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        string name;
        int a, b, c;
        cin >> name >> a >> b >> c;
        if (a < 0) a = inf;
        if (b < 0) b = inf;
        if (c < 0) c = inf;
        t[i] = min(a, min(b, c));
    }
    sort(t + 1, t + 1 + n);
    int cur = 0;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (cur + t[i] <= 300) {
            ans++;
            cur += t[i];
        }
        else break;
    }
    cout << ans;
}

