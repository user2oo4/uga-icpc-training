#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;

struct ST {
    int val[maxN * 4];
    int mn[maxN * 4];
    int lz[maxN * 4];
    int n;
    void push(int id, int tl, int tr) {
        if (lz[id]) {
            mn[id] = lz[id];
            if (tl != tr) {
                lz[id * 2] = lz[id];
                lz[id * 2 + 1] = lz[id];
            }
            lz[id] = 0;
        }
    }
    void upd(int id = 1, int tl = 1, int tr = n, int l, int r, int val) {
        if (l > tr || r < tl) return;

    }
}