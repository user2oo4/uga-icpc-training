#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxN = 1e5 + 5;
const int maxA = 200 + 2;

int n;
int a[maxN];
int b[maxN];
int cnt[maxN];

int manacher() {
    array<vector<int>,2> p = {vector<int>(n+1), vector<int>(n)};
    for (int z = 0; z < 2; z++) {
        for (int i = 0, l = 0, r = 0; i < n; i++) {
            int t = r - i + !z;
            if (i < r) p[z][i] = min(t, p[z][l+t]);
            int L = i-p[z][i], R = i+p[z][i] - !z;
            while (L>=1 && R+1<n && b[L - 1 + 1] == b[R + 1 + 1]) p[z][i]++, L--, R++;
            if (R>r) l=L, r=R;
        }
    }
    
    int res = 0;
    for (auto x : p[0]) res += x;
    return res;
}

int calc(int k) {
    for (int i = 1 ; i <= n ; i++) {
        b[i] = a[i] % k;
        if (i & 1) {
            b[i] = k - b[i];
            if (b[i] == k) b[i] = 0;
        }
    }
    return manacher();
}

void process() {
    for (int i = 200 ; i >= 1 ; i--) {
        for (int j = 2 ; i * j <= 200 ; j++) {
            cnt[i] -= cnt[i * j];
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= 200 ; i++) {
        ans += i * cnt[i];
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    for (int i = 1 ; i <= 200 ; i++) {
        cnt[i] = calc(i);
    }
    process();
}