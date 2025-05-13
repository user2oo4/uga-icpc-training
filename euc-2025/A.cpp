#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
// #define int long long

const int maxN = 55 + 5;
vector<ii> edges;
vector<ii> AdjList[maxN];
bool vis[maxN];
vector<int> ans[3];
int n, m;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    cout << "YES" << endl;
    cout << 2 * m << "\n";
    for(int i = 1 ; i <= m ; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 1 ; j <= n ; j++) {
            if (j != a && j != b) cout << j << " ";
        }
        cout << a << " " << b << endl;
        cout << a << " " << b << " ";
        for (int j = n ; j >= 1 ; j--) {
            if (j != a && j != b) cout << j << " ";
        }
        cout << endl;
    }
}