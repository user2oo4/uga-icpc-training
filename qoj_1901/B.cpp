#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) {
    return rng() % (r - l + 1) + l;
}

const int maxN = 3e5 + 5;
const int maxT = 6e5 + 5;
const int T = 6e5;

struct SegmentTree {
    int sum[maxT * 4];
    int lz[maxT * 4];
    void push(int id, int l, int r) {
        if (lz[id]) {
            sum[id] = (r -l + 1) * lz[id];
            if (l != r) {
                lz[id * 2] = lz[id];
                lz[id * 2 + 1] = lz[id];
            }
        }
        lz[id] = 0;
    }
    void upd(int l, int r, int val, int id = 1, int tl = 1, int tr = T) {
        push(id, tl, tr);
        if (l > tr || r < tl) return;
        if (l <= tl && tr <= r) {
            // cout << "update " << tl << " " << tr << " " << val << endl;
            lz[id] = val;
            push(id, tl, tr);
            return;
        }
        int mid = (tl + tr) / 2;
        upd(l, r, val, id * 2, tl, mid);
        upd(l, r, val, id * 2 + 1, mid + 1, tr);
        push(id * 2, l, mid);
        push(id * 2 + 1, mid + 1, r);
        sum[id] = sum[id * 2] + sum[id * 2 + 1];
    }
    int get(int pos, int id = 1, int tl = 1, int tr = T) {
        push(id, tl, tr);
        if (tl > pos || tr < pos) return 0;
        if (tl == pos && tr == pos) return sum[id];
        int mid = (tl + tr) / 2;
        return get(pos, id * 2, tl, mid) + get(pos, id * 2 + 1, mid + 1, tr);
    }
} ans, e;

void start() {
    e.upd(1, T, maxT); // end segtree
}

void add(int l, int r) {
    cout << "l r " << l << " " << r << endl;
    if (e.get(l) <= r) return;
    
    // position that end maybe updated
    int s_l = 1;
    int s_r = l;
    while (s_l < s_r) {
        cout << "sl sr = " << s_l << " " << s_r << endl;
        int s_mid = (s_l + s_r) / 2;
        cout << "e.get(s_mid) = " << e.get(s_mid) << endl;
        if (e.get(s_mid) > r) s_r = s_mid;
        else s_l = s_mid + 1;
    }
    int st = s_r;
    int en = l;
    cout << "st en " << st << " " << en << endl;
    e.upd(st, en, r);
    ans.upd(st, en, ans.get(r + 1) + 1);
}

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    start();
    cout << "start done " << endl;
    for (int i = 1 ; i <= n ; i++) {
        int l, r;
        cin >> l >> r;
        add(l, r);
        cout << ans.get(1) << endl;
        for (int j = 1 ; j <= T ; j++) {
            int x = e.get(j);
            if (x == maxT) break;
            else {
                cout << "end " << j << " = " << x << endl;
                cout << "ans " << j << " = " << ans.get(j) << endl;
            }
        }
        cout << endl;
    }
}

