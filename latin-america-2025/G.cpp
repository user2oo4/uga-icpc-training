#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;

const int maxN = 2e5 + 5;
int n;
char c;
int l, p;
map<int, int> M;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    M[1] = 1;
    for (int i = 0; i < n; i++) {
        cin >> c >> l >> p;
        if (c == '-') {
            auto it = M.upper_bound(p);
            if (it != M.end() && (*it).first < p + l) {
                cout << 'U';
            } else {
                cout << 'S';
                M[p]++;
                if (!M[p]) M.erase(p);
                M[p + l]--;
                if (!M[p + l]) M.erase(p + l);
            }
        } else {
            cout << 'S';
            M[p] += l;
            if (!M[p]) M.erase(p);
            M[p + 1] -= l;
            if (!M[p + 1]) M.erase(p+1);
        }
    }
}