#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a ; i < (b) ; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxN = 2025;
int tc;
int n;
int a[maxN];
int b[maxN];
int pa[maxN];
int pb[maxN];
vector<pii> moves;

void sw(int x, int y) {
    // swap numbers x, y
    // cout << "swap " << x << " " << y << endl;
    int px = pa[x];
    int py = pa[y];
    moves.push_back(pii(px, py));
    swap(a[px], a[py]);
    swap(pa[x], pa[y]);
}

bool solve(int x) {
    // solve number x
    if (pa[x] > pb[x]) {
        return false;
    }
    // cout << "pos a " << x << " = " << pa[x] << endl;
    // cout << "pos b " << x << " = " << pb[x] << endl;
    if (pa[x] == pb[x]) return true;
    stack<int> st, st2;
    for (int i = pa[x] + 1 ; i <= pb[x] ; i++) {
        if (a[i] > x) continue;
        while (!st.empty() && st.top() < a[i]) st.pop();
        st.push(a[i]);
    }
    while (!st.empty()) {
        int t = st.top();
        st.pop();
        st2.push(t);
    }
    while (!st2.empty()) {
        int t = st2.top();
        st2.pop();
        sw(x, t);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tc;
    while (tc--) {
        moves.clear();
        cin >> n;
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
            pa[a[i]] = i;
        }
        for (int i = 1 ; i <= n ; i++) {
            cin >> b[i];
            pb[b[i]] = i;
        }
        bool ok = true;
        for (int i = n ; i >= 1 ; i--) {
            if (!solve(i)) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }
        cout << sz(moves) << '\n';
        for (pii tmp: moves) cout << tmp.first << " " << tmp.second << '\n';
    }
}