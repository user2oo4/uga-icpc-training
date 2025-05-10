#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e9;

typedef pair<int, int> ii;

const int maxN = 1001;

#define x first
#define y second

int n;

ii pt[maxN];
int min_x, max_x, min_y, max_y;
vector<ii> upper_half;
vector<ii> lower_half;
vector<ii> ans;

void push_upper(ii tmp) {
    if (ans.empty()) {
        ans.push_back(tmp);
        return;
    }
    ii prv = ans.back();
    if (prv == tmp) return;
    if (prv.x > tmp.x) ans.pop_back();
    ans.push_back(tmp);
    return;
}

void push_lower(ii tmp) {
    if (ans.empty()) {
        ans.push_back(tmp);
        return;
    }
    ii prv = ans.back();
    if (prv == tmp) return;
    if (prv.x < tmp.x) ans.pop_back();
    ans.push_back(tmp);
    return;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    min_x = min_y = 1e9;
    max_x = max_y = 1;
    for (int i = 1 ; i <= n ; i++) {
        cin >> pt[i].x >> pt[i].y;
        min_x = min(min_x, pt[i].x);
        max_x = max(max_x, pt[i].x);
        min_y = min(min_y, pt[i].y);
        max_y = max(max_y, pt[i].y);
    }
    int mid = (min_y + max_y) / 2;
    for (int i = 1 ; i <= n ; i++) {
        if (pt[i].y >= mid) {
            upper_half.push_back(pt[i]);
            upper_half.push_back(ii(pt[i].x, mid));
            if (pt[i].x != inf) upper_half.push_back(ii(pt[i].x + 1, mid));
            else upper_half.push_back(ii(pt[i].x - 1, mid));
        }
        else {
            lower_half.push_back(pt[i]);
            lower_half.push_back(ii(pt[i].x, mid - 1));
            if (pt[i].x != 1) lower_half.push_back(ii(pt[i].x - 1, mid - 1));
            else lower_half.push_back(ii(pt[i].x + 1, mid - 1));
        }
    }
    sort(upper_half.begin(), upper_half.end());
    auto it1 = upper_bound(upper_half.begin(), upper_half.end(), ii(inf, 0));
    reverse(it1, upper_half.end());
    sort(lower_half.begin(), lower_half.end());
    auto it2 = upper_bound(lower_half.begin(), lower_half.end(), ii(2, 0));
    reverse(lower_half.begin(), it2);
    reverse(lower_half.begin(), lower_half.end());
    ii prv = ii(0, 0);
    for (ii p: upper_half) {
        if (p != prv) ans.push_back(p);
        prv = p;
    }
    prv = ii(0, 0);
    for (ii p: lower_half) {
        if (p != prv) ans.push_back(p);
        prv = p;
    }
    if (min_y == max_y) {
        int y = (min_y - 1)? (min_y - 1): min_y + 1;
        ans.push_back(ii(1, y));
    }
    cout << ans.size() << endl;
    for (ii p: ans) {
        cout << p.x << " " << p.y << endl;
    }
}