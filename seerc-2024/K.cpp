#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxN = 2e5 + 5;
int n, q;
int a[maxN];
string s;

int sum[maxN * 4];
int lz[maxN * 4];

void push(int id, int tl, int tr) {
    if (lz[id]) {
        sum[id] <<= lz[id];
        if (tl != tr) {
            lz[id * 2] += lz[id];
            lz[id * 2 + 1] += lz[id];
        }
        lz[id] = 0;
    }
}

void build(int id = 1, int tl = 1, int tr = n) {
    if (tl == tr) {
        sum[id] = 1;
        return;
    }
    int mid = (tl + tr) / 2;
    build(id * 2, tl, mid);
    build(id * 2 + 1, mid + 1, tr);
    sum[id] = sum[id * 2] + sum[id * 2 + 1];
}

void add(int pos, int val, int id = 1, int tl = 1, int tr = n) {
    push(id, tl, tr);
    if (tl > pos || tr < pos) return;
    if (tl == tr) {
        sum[id] += val;
        return;
    }
    int mid = (tl + tr) / 2;
    add(pos, val, id * 2, tl, mid);
    add(pos, val, id * 2 + 1, mid + 1, tr);
    sum[id] = sum[id * 2] + sum[id * 2 + 1];
}

void mul2(int l, int r, int id = 1, int tl = 1, int tr = n) {
    push(id, tl, tr);
    if (tl > r || tr < l) return;
    if (l <= tl && tr <= r) {
        lz[id]++;
        push(id, tl, tr);
        return;
    }
    int mid = (tl + tr) / 2;
    mul2(l, r, id * 2, tl, mid);
    mul2(l, r, id * 2 + 1, mid + 1, tr);
    sum[id] = sum[id * 2] + sum[id * 2 + 1];
}

int get_sum(int l, int r, int id = 1, int tl = 1, int tr = n) {
    push(id, tl, tr);
    if (tl > r || tr < l) return 0;
    if (l <= tl && tr <= r) return sum[id];
    int mid = (tl + tr) / 2;
    return get_sum(l, r, id * 2, tl, mid) + get_sum(l, r, id * 2 + 1, mid + 1, tr);
}

int find(int val) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (get_sum(1, mid) >= val)
            r = mid;
        else
            l = mid + 1;
    }
    return r;
}

void print(int id = 1, int tl = 1, int tr = n) {
    push(id, tl, tr);
    if (tl == tr) {
        cout << "a " << tl << " = " << sum[id] << endl;
        return;
    }
    print(id * 2, tl, (tl + tr) / 2);
    print(id * 2 + 1, (tl + tr) / 2 + 1, tr);
}





signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> q;
    cin >> s;
    s = ' ' + s;
    for (int i = 1 ; i <= n ; i++) {
        a[i] = 1;
    }
    build();
    int type, l, r;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> l >> r;
            int bl_l = find(l);
            int bl_r = find(r);
            // cout << "l r " << bl_l << " " << bl_r << endl;
            if (bl_l == bl_r) {
                add(bl_l, r - l + 1);
            } else {
                int sum_l = get_sum(1, bl_l);
                int sum_r = get_sum(1, bl_r - 1);
                add(bl_l, sum_l - l + 1);
                add(bl_r, r - sum_r);
                mul2(bl_l + 1, bl_r - 1);
            }
            // print();
        } else {
            cin >> l;
            int bl = find(l);
            cout << s[bl] << endl;
        }
    }
}