#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii; 
typedef pair<ii, ii> iiii;

const int maxN = 1e5 + 5;
const int bl = 300;
const int inf = 1e9 + 7;

int n, q;
struct tree{
    int x;
    int y;
    int h;
    tree(int _x, int _y, int _h): x(_x), y(_y), h(_h) {}
};

struct query{
    int id;
    int x_low;
    int x_high;
    int y_low;
    int y_high;
    query(int _id, int _xl, int _xh, int _yl, int _yh): id(_id), x_low(_xl), x_high(_xh), y_low(_yl), y_high(_yh) {}
};

vector<tree> trees;
vector<query> queries;
vector<int> ans;
ii trees_x[maxN]; // trees at x (only y and h) 

void input() {
    cin >> n >> q;
    ans.assign(q + 1, 0);
    for (int i = 1 ; i <= n ; i++) {
        int x, y, h;
        cin >> x >> y >> h;
        trees.push_back(tree(x, y, h));
    }
    for (int i = 1 ; i <= q ; i++) {
        int xl, yl, xh, yh;
        cin >> xl >> yl >> xh >> yh;
        queries.push_back(query(i, xl, xh, yl, yh));
    }
}

bool cmp_trees_x(tree t1, tree t2) {
    return t1.x < t2.x;
}

void process() {
    sort(trees.begin(), trees.end(), cmp_trees_x);
    map<int, int> Mx;
    int cur = 0;
    for (int i = 0 ; i < n ; i++) {
        if (!i || trees[i].x != cur) {
            Mx[trees[i].x] = i + 1;
            // cout << "Mx " << trees[i].x << " = " << i + 1 << endl;
        }
        cur = trees[i].x;
        trees[i].x = i + 1;
    }
    Mx[inf] = n + 1;

    for (tree t: trees) {
        trees_x[t.x] = ii(t.y, t.h);
    }

    for (query &q: queries) {
        q.x_high = Mx.upper_bound(q.x_high)->second - 1;
        q.x_low = Mx.lower_bound(q.x_low)->second;
    }
}

bool cmp_queries(query q1, query q2) {
    if (q1.x_low / bl != q2.x_low / bl) {
        return q1.x_low / bl < q2.x_low / bl;
    }
    if (q1.x_high / bl != q2.x_high / bl) {
        return (q1.x_high / bl < q2.x_high / bl) ^ ((q1.x_low / bl) & 1);
    }
    if (q1.x_low != q2.x_low) return q1.x_low < q2.x_low;
    return q1.x_high > q2.x_high;
}

bool cmp_trees(tree t1, tree t2) {
    return t1.x < t2.x;
}

set<iii> S; // (y, h), x

void add(int x) {
    S.insert(iii(ii(trees_x[x].first, trees_x[x].second), x));
}

void remove(int x) {
    S.erase(iii(ii(trees_x[x].first, trees_x[x].second), x));
}

void solve() {
    sort(trees.begin(), trees.end(), cmp_trees);
    sort(queries.begin(), queries.end(), cmp_queries);
    int lx = 1;
    int rx = 0; // current left and right x
    int i = 0;
    vector<int> vt;
    for (query q: queries) {
        while (rx < q.x_high) {
            rx++;
            S.insert(iii(ii(trees_x[rx].first, trees_x[rx].second), rx));
        }
        while (lx > q.x_low) {
            lx--;
            S.insert(iii(ii(trees_x[lx].first, trees_x[lx].second), lx));
        }
        while (rx > q.x_high) {
            S.erase(iii(ii(trees_x[rx].first, trees_x[rx].second), rx));
            rx--;
        }
        while (lx < q.x_low) {
            S.erase(iii(ii(trees_x[lx].first, trees_x[lx].second), lx));
            lx++;
        }
        // if (!(i & 1023)) cout << "move " << i << " = " << move << endl;
        // solve query here
        auto it1 = S.lower_bound(iii(ii(q.y_low, 0), 0));
        auto it2 = S.lower_bound(iii(ii(q.y_high + 1, 0), 0));
        int d = distance(it1, it2);
        // if (d >= 45) {
        //     ans[q.id] = 1;
        // }
        // else if (d < 3) {
        //     ans[q.id] = 0;
        // }
        // else {
        //     for (auto it = it1 ; it != it2 ; it++) {
        //         vt.push_back((*it).first.second); // push h in vector
        //     }
        //     sort(vt.begin(), vt.end());
        //     int len = (int)vt.size();
        //     for (int i = 0 ; i + 2 < len ; i++) {
        //         if (vt[i] + vt[i + 1] > vt[i + 2]) {
        //             ans[q.id] = 1;
        //             break;
        //         }
        //     }
        //     vt.clear();
        // }
    }

    // for (int i = 1 ; i <= q ; i++) {
    //     cout << ans[i] << endl;
    // }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
    // Code to be measured goes here
    input();
    process();
    solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;
    
}