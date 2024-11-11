#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
const int maxN = (1 << 18) + 5;
int rating[maxN];

int solve(int l, int r) {
    // from id l to id r
    // guarantee to be even length
    int ans = 0;
    int id1 = (l + r) / 2;
    int id2 = r;
    while(id1 >= 0 && id2 > (l + r) / 2) {
        // cout << "id1 id2 " << id1 << " " << id2 << endl;
        // cout << "rating diff = " << rating[id1] - rating[id2] << endl;
        if (rating[id1] - rating[id2] > k) id2--;
        else {
            ans++;
            id1--;
            id2--;
        }
    }
    return ans;
}

signed main() {
    cin >> n >> k;
    for (int i = 0 ; i < (1 << n) ; i++) {
        cin >> rating[i];
    }
    sort(rating, rating + (1 << n), greater<int>());
    int ans = 0;
    for (int i = n ; i >= 1 ; i--) {
        ans += solve(0, (1 << i) - 1);
    }
    cout << ans;
}