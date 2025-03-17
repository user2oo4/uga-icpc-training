#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) {
    return rng() % (r - l + 1) + l;
}

const int maxN = 1005;
int n;

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    int rows = (n + 20) / 21;
    int cols = (n + 6) / 7;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            int cr = (i + 20) / 21;
            int cc = (j + 6) / 7;
            cout << (cr - 1) * cols + cc << " ";
        }
        cout << endl;
    }
}