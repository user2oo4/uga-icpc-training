#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) {
    return rng() % (r - l + 1) + l;
}

int ask(int i1, int i2) {
    cout << i1 << " " << i2 << endl;
    int ans;
    cin >> ans;
    return ans;
}

void ask(vector<int> &number) {
    vector<vector<int>> dist(51, vector<int>());
    int n = (int)number.size();
    for (int i = 1 ; i < n ; i++) {
        int x = ask(number[0], number[i]);
        if (x == 0) {
            exit(0);
        } else {
            dist[x].push_back(number[i]);
        }
    }
    for (int i = 1 ; i <= 50 ; i++) {
        if (!dist[i].empty()) ask(dist[i]);
    }
}

signed main() {
    vector<int> vt;
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) vt.push_back(i);
    ask(vt);
}