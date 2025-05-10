#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
vector<ii> vt;

ii merge(ii a, ii b, int r1, int r2, int side) {
    // r1: rotate 1
    // r2: rotate 2
    // side: either l-r or u-d
    if (r1) swap(a.first, a.second);
    if (r2) swap(b.first, b.second);
    if (!side) {
        if (a.first == b.first) {
            return ii(a.first, a.second + b.second);
        }
        else return ii(-1, -1);
    } else {
        if (a.second == b.second) {
            return ii(a.first + b.first, a.second);
        }
        else return ii(-1, -1);
    }
} 

void solve(vector<ii> vt) {
    int len = (int)vt.size();
    // cout << "len = " << len << endl;
    // for (ii tmp: vt) {
    //     cout << tmp.first << " " << tmp.second << endl;
    // }
    if (len == 1) {
        if (vt[0].first == vt[0].second) {
            cout << 1;
            exit(0);
        }
        else return;
    } 
    vector<ii> nw;
    for (int i1 = 0 ; i1 < len ; i1++) {
        for (int i2 = i1 + 1 ; i2 < len ; i2++) {
            nw.clear();
            for (int i = 0 ; i < len ; i++) {
                if (i != i1 && i != i2) nw.push_back(vt[i]);
            }
            for (int r1 = 0 ; r1 < 2 ; r1++) {
                for (int r2 = 0 ; r2 < 2 ; r2++) {
                    for (int side = 0 ; side < 2 ; side++) {
                        ii tmp = merge(vt[i1], vt[i2], r1, r2, side);
                        if (tmp.first == -1) continue;
                        nw.push_back(tmp);
                        solve(nw);
                        nw.pop_back();
                    }
                }
            }
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    vector<ii> vt;
    for (int i = 0 ; i < 4 ; i++) {
        int x, y;
        cin >> x >> y;
        vt.push_back(ii(x, y));
    }
    solve(vt);
    cout << 0;
}