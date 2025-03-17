#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) {
    return rng() % (r - l + 1) + l;
}

const int maxN = 50005;
const int maxQ = 5e5 + 5;
vector<vector<double>> vt;
vector<int> group_size;
int n, q;
int groups;

int merge(vector<double> &r, vector<double> &x, vector<double> &y) {
    double sum = 0;
    for (int i = 0 ; i < groups ; i++) {
        // cout << "x " << i << " = " << x[i] << endl;
        // cout << "y " << i << " = " << y[i] << endl;
        r[i] = x[i] + y[i] - x[i] * y[i] / group_size[i];
        sum += r[i];
    }
    // cout << "sum = " << sum << endl;
    return round(sum);
}

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> q;
    groups = min(n, 200);
    vt.assign(n + q + 1, vector<double>(groups, 0));

    int common_group = (n + groups - 1) / groups;
    int last_group = n % common_group;
    group_size.assign(groups - 1, common_group);
    if (!last_group) group_size.push_back(common_group);
    else group_size.push_back(last_group);

    
    for (int i = 1 ; i <= n ; i++) {
        vt[i][(i - 1) / common_group] = 1;
    }
    for (int i = 1 ; i <= q ; i++) {
        int x, y;
        cin >> x >> y;
        cout << merge(vt[n + i], vt[x], vt[y]) << endl;
    }

}
