#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef pair<int, int> ii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const int maxN = 5e5 + 5;
int p;
int n, e;
ordered_set S;
map<int, int> cur_add;
int pos[maxN * 2];
char c;
int k, x, y, z;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> p;
        S.insert(ii(i * 1000000, p));
        pos[p] = i * 1000000;
    }
    cin >> e;
    while (e--) {
        cin >> c;
        if (c == '+') {
            cin >> y >> z;
            pos[y] = pos[z] - 1;
            S.insert(ii(pos[y], y));
            n++;
        } else if (c == '-') {
            cin >> x;
            auto it = S.find(ii(pos[x], x));
            S.erase(it);
            n--;
        } else {
            cin >> k;
            vector<int> vt(2 * k, 0);
            for (int i = 0 ; i < k ; i++) {
                cin >> vt[i];
                vt[i + k] = vt[i];
            }
            int cur_pos = -1;
            int cur_len = 0;
            int best_len = 0;
            cout << "current set = " << endl;
            for (auto it: S) {
                cout << it.first << " " << it.second << endl;
            }
            for (int i = 0 ; i < 2 * k ; i++) {
                auto it = S.find(ii(pos[vt[i]], vt[i]));
                if (it == S.end()) {
                    best_len = max(best_len, cur_len);
                    cur_len = 0;
                    cur_pos = -1;
                    continue;
                }
                int new_pos = S.order_of_key(ii(pos[vt[i]], vt[i]));
                if (cur_pos == -1 || new_pos == (cur_pos + 1) % n) {
                    cur_len++;
                } else {
                    best_len = max(best_len, cur_len);
                    cur_len = 1;
                }
                best_len = max(best_len, cur_len);
                cur_pos = new_pos;
                cout << "i = " << i << endl;
                cout << "cur_pos = " << cur_pos << endl;
            }
            best_len = max(best_len, cur_len);
            if (best_len > k) cout << '*' << endl;
            else cout << best_len << endl;
        }
    }
}