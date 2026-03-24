#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;

const int maxN = 3e5 + 5;
int a[maxN];
int cnt[5];

int n;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        cnt[a[i] % 5]++;
    }
    int ans = cnt[1] + cnt[2] * 2;
    while (cnt[3] || cnt[4]) {
        if (cnt[3] && cnt[4]) {
            cnt[3]--; cnt[4]--;
            ans += 2;
        }
        else if (cnt[3]) {
            if (cnt[3] >= 2) {
                cnt[3] -= 2;
                ans++;
            } else {
                cnt[3] -= 1;
                ans -= 2;
            }
        } else {
            if (cnt[4] >= 2) {
                cnt[4] -= 2;
                cnt[3]++;
            } else {
                cnt[4]--;
                ans -= 1;
            }
        }
    }
    cout << ans;
}