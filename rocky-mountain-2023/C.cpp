#include <bits/stdc++.h>
using namespace std;

const int maxN = 1005;
const int maxM = 16;

int n, m, q;
char ans[maxN][maxM];
pair<int, char> should[maxM];


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> q;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> ans[i][j];
        }
    }
    for (int i = 1 ; i <= q ; i++) {
        int id;
        char c;
        cin >> id >> c;
        should[i] = make_pair(id, c);
    }
    vector<int> res;
    for (int i = 1 ; i <= n ; i++) {
        int cnt = 0;
        for (int j = 1 ; j <= q ; j++) {
            char c = should[j].second;
            int id = should[j].first;
            if (c == ans[i][id]) cnt++;
            else break;
        }
        if (cnt == q) res.push_back(i);
    }
    if (res.size() == 1) {
        cout << "unique" << endl;
        cout << res.back();
    } else {
        cout << "ambiguous" << endl;
        cout << (int)res.size();
    }
}