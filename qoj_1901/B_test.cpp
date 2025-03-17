#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) {
    return rng() % (r - l + 1) + l;
}

int solve(vector<ii>* v) {
    sort(v->begin(), v->end());

    int events = 0;
    int next = -1; 
    for (const auto&[r, l]: *v) {
        if (l > next) {
            events++;
            next = r;
        }
    }

    return events;
}

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    vector<ii> v;

    int l, r;
    while (n--) {
        cin >> l >> r;
        v.push_back({r, l});
        cout << solve(&v) << endl;
    }
}

