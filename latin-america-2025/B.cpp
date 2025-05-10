#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int maxN = 1505;

bitset<maxN> basis[maxN];
bitset<maxN> who[maxN];
int sz;
int d, n;

void insertVector(bitset<maxN> bit, int id) {
    bitset<maxN> tmp = bit;
    bitset<maxN> mask;
    mask.reset();
    mask[id] = 1;

    for (int i = d; i >= 0; --i) {
        if (!tmp[i]) continue;
        if (basis[i].none()) {
            basis[i] = tmp;
            who[i] = mask;
            ++sz;
            return;
        }
        tmp ^= basis[i];
        mask ^= who[i];
    }
    int cur = 0;
    for (int i = 0 ; i < n ; i++) {
        if (mask[i]) {
            cout << cur + 1;
            cur ^= 1;
        } else cout << 0;
    }
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> d;
    vector<bitset<maxN>> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < d; j++) {
            a[i][j] = s[j] - '0';
        }
        a[i][d] = 1;
    }

    for (int i = 0; i < n; i++) {
        insertVector(a[i], i);
    }
    cout << "*";
}
