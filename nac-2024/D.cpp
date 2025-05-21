#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int maxN = 5e4 + 5;
int a[maxN];
int b[maxN];
int pos[maxN];
int n, m;

bool test_fw() {
    int p = pos[b[0]];
    for (int i = 1 ; i < m ; i++) {
        int ex = (p + 1) % n;
        p = pos[b[i]];
        if (p != ex) return false;
    }
    return true;
}

bool test_bw() {
    int p = pos[b[0]];
    for (int i = 1 ; i < m ; i++) {
        int ex = (p - 1 + n) % n;
        p = pos[b[i]];
        if (p != ex) return false;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int j = 0 ; j < m ; j++) {
        cin >> b[j];
    }
    if (test_fw()) cout << 1;
    else if (test_bw()) cout << 1;
    else cout << 0;
}