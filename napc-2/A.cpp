#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a ; i < (b) ; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    ld ans = 1.0;
    for (int i = 1 ; i <= n ; i++) {
        ans *= (i * i);
        ans /= n;
    }
    cout << fixed << setprecision(20) << ans;
}