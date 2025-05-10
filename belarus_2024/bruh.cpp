#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r) {
    return rng() % (r - l + 1) + l;
}

int tc;
int a;
const int mod = (1 << 8);

int find_cycle(int x) {
    int cur_pw = x;
    int cycle = 1;
    while (true) {
        cout << "cycle b = " << cycle << " " << (cur_pw ^ x) << endl;
        if (cycle == (cur_pw^x)) return cycle;
        if (cur_pw == 1) return -1;
        cur_pw = cur_pw * x % mod;
        cycle++;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("output2.txt", "w", stdout);
    int n = 1;
    for (int i = 1 ; i <= n ; i += 2) {
        int x = 5;
        cout << x << " " << find_cycle(x) << endl;
    }
}