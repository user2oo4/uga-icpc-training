#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> ii;

const int maxM = 1e5 + 5;
const int maxK = 2e5 + 5;
int pa, pb;
int n, m, k;

int a[maxM];
int b[maxM];
int cur_a[maxM];
int cur_b[maxM];
int cur_ab[maxM];

int pos[maxK];
int type[maxK];
int num[maxK];
int cost[maxK];

int can[maxM][4]; // 1: A, 2: B, 3: AB

bool check(int x) {
    // time = x
    for (int i = 1 ; i <= m ; i++) {
        can[i][1] = can[i][2] = can[i][3] = 0;
    }
    for (int i = 1 ; i <= k ; i++) {
        int da = pa - pos[i];
        if (da < 0) da += n;
        int db = pb - pos[i];
        if (db < 0) db += n;
        int id = 0;
        if (da <= x) id += 1;
        if (db <= x) id += 2;
        can[type[i]][id] += num[i]; 
    }
    for (int i = 1 ; i <= m ; i++) {
        if (a[i] + b[i] <= can[i][1] + can[i][2] + can[i][3]
        && a[i] <= can[i][1] + can[i][3]
        && b[i] <= can[i][2] + can[i][3]) {
            continue;
        }
        return false;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> pa >> pb;
    for (int i = 1 ; i <= m ; i++) cin >> a[i];
    for (int i = 1 ; i <= m ; i++) cin >> b[i];
    for (int i = 1 ; i <= k ; i++) cin >> pos[i] >> type[i] >> num[i] >> cost[i];
    int l = 0;
    int r = n;
    if (!check(n)) {
        cout << "impossible";
        return 0;
    }
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    int ans = l;
    cout << ans << " ";

    int ans_cost = 0;
    priority_queue<ii> pq;
    for (int i = 1 ; i <= k ; i++) {
        pq.push(ii(-cost[i], i));
    }
    for (int i = 1 ; i <= m ; i++) {
        can[i][1] = can[i][2] = can[i][3] = 0;
    }
    while (!pq.empty()) {
        int i = pq.top().second;
        pq.pop();
        int da = pa - pos[i];
        if (da < 0) da += n;
        int db = pb - pos[i];
        if (db < 0) db += n;
        int id = 0;
        if (da <= ans) id += 1;
        if (db <= ans) id += 2;
        if (id == 0) continue;
        // cout << "id " << i << " = " << id << endl;
        // cout << "can 1 2 3 = " << can[type[i]][1] << " " << can[type[i]][2] << " " << can[type[i]][3] << endl;
        // cout << "a b " << type[i] << " = " << a[type[i]] << " " << b[type[i]] << endl;
        int x = max({a[type[i]] + b[type[i]] - can[type[i]][1] - can[type[i]][2] - can[type[i]][3],
        a[type[i]] - can[type[i]][1] - can[type[i]][3],
        b[type[i]] - can[type[i]][2] - can[type[i]][3],
        0ll});
        if (id == 1) {
            int sa = can[type[i]][1] + max(0ll, can[type[i]][3] - max(0ll, b[type[i]] - can[type[i]][2]));
            x = max(0ll, a[type[i]] - sa);
        }
        if (id == 2) {
            int sb = can[type[i]][2] + max(0ll, can[type[i]][3] - max(0ll, a[type[i]] - can[type[i]][1]));
            x = max(0ll, b[type[i]] - sb);
        }
        // cout << "need = " << x << endl;
        int get = min(x, num[i]);
        can[type[i]][id] += get;
        // cout << "take = " << get << endl << endl;
        ans_cost += get * cost[i];
    }
    cout << ans_cost << endl;
}