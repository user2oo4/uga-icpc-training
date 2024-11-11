#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

struct TwoSat{
    int N;
    vector<vi> gr;
    vi values; // 0: false, 1: true
    
    TwoSat(int n = 0): N(n), gr(2*n) {}

    void either(int f, int j) {
        f = max(2 * f, -1 - 2 * f);
        j = max(2 * j, -1 - 2 * j);
        gr[f].push_back(j ^ 1);
        gr[j].push_back(f ^ 1);
    }
    void setValue(int x) {
        either(x, x);
    }

    vi val, comp, z;
    int time = 0;

    int dfs(int i) {
        int low = val[i] = ++time, x;
        z.push_back(i);
        for (int e: gr[i]) {
            if (!comp[e]) {
                low = min(low, val[e]?: dfs(e));
            }
        }
        if (low == val[i]) do {
            x = z.back(); z.pop_back();
            comp[x] = low;
            if (values[x>>1] == -1) {
                values[x>>1] = x & 1;
            } 
        } while (x != i);
        return val[i] = low;
    }

    bool solve() {
        values.assign(N, -1);
        val.assign(2*N, 0);
        comp = val;
        for (int i = 0 ; i < 2 * N ; i++) {
            if (!comp[i]) dfs(i);
        }
        for (int i = 0 ; i < N ; i++) {
            if (comp[2 * i] == comp[2 * i + 1]) return 0;
        }
        return 1;
    }
};

const int maxN = 101;
char c[maxN][maxN];
int n, k;
bool current[maxN];

signed main() {
    cin >> n >> k;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < k ; j++) {
            cin >> c[i][j];
        }
    }

    vi cur_val;
    
    for (int id = 0 ; id <= k ; id++) {
        TwoSat ts(k);
        for (int j = 0 ; j < id ; j++) {
            if (!current[j]) ts.setValue(~j);
            else ts.setValue(j);
            // cout << "current " << j << " = " << current[j] << endl;
        }
        for (int i = 0 ; i < n ; i++) {
            for (int j1 = 0 ; j1 < k ; j1++) {
                if (c[i][j1] == 'X') continue;
                for (int j2 = j1 + 1 ; j2 < k ; j2++) {
                    if (c[i][j2] == 'X') continue;
                    if (c[i][j1] == 'T') {
                        if (c[i][j2] == 'T') ts.either(~j1, ~j2);
                        else ts.either(~j1, j2);
                    } else {
                        if (c[i][j2] == 'T') ts.either(j1, ~j2);
                        else ts.either(j1, j2);
                    }
                }
            }
        }
        if (ts.solve()) {
            cur_val = ts.values;
            // for (int u: ts.values) cout << u;
            // cout << endl;
        }
        else if (id == 0) {
            cout << -1;
            return 0;
        }
        else {
            current[id - 1] = 1;
            id--;
        }
    }
    for (int i = 0 ; i < k ; i++) {
        if (!current[i]) cout << 'F';
        else cout << 'T';
    }
    
}