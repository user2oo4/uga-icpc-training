#include <bits/stdc++.h>
using namespace std;
// #define int long long
typedef pair<int, int> ii;
typedef long double ld;

const int maxN = 2e5 + 5;
map<ii, int> M;
int cur = 1;
int q, w;

struct IT {
    int sum;
    int val;
    int lc;
    int rc;
} node[maxN * 4];

void push(int id, int l, int r) {
    if (node[id].val) {
        node[id].sum = r - l + 1;
    } else {
        node[id].sum = node[node[id].lc].sum + node[node[id].rc].sum;
    }
    // cout << "sum " << id << " = " << node[id].sum << endl;
}

void update(int id, int tl, int tr, int l, int r, int v) {
    // cout << "update " << id << " " << tl << " " << tr << endl;
    if (tl > r || tr < l) return;
    if (l <= tl && tr <= r) {
        node[id].val += v;
        push(id, tl, tr);
        return;
    }
    int mid = (tl + tr) / 2;
    if (!node[id].lc) {
        node[id].lc = ++cur;
    }
    update(node[id].lc, tl, mid, l, r, v);
    if (!node[id].rc) {
        node[id].rc = ++cur;
    }
    update(node[id].rc, mid + 1, tr, l, r, v);
    push(id, tl, tr);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> q >> w;
    while (q--) {
        int x, y;
        cin >> x >> y;
        M[ii(x, y)] ^= 1;
        int v = (M[ii(x, y)])? 1: -1;
        int l = max(x - y, 0);
        int r = min(x + y, w) - 1;
        // cout << "l r " << l << " " << r << endl;
        update(1, 0, w, l, r, v);
        ld ans = sqrt(2) * node[1].sum;
        cout << fixed << setprecision(9) << ans << endl;
    }
}