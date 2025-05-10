#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;

vector<int> add;
vector<int> mul;
int att;
int n, p, h;

int get_new_power() {
    int cur_p = p;
    for (int u: add) {
        if (h - cur_p <= u) return -1;
        cur_p += u;
    }
    for (int u: mul) {
        if (cur_p * u >= h) return -1;
        cur_p *= u;
    }
    return cur_p;
}

bool ck(int i, int j, int k) {
    cout << "ck " << i << " " << j << " " << k << endl;
    int cur_p = p;
    for (int u: add) {
        if (!i) break;
        if (h - cur_p <= u) return -1;
        cur_p += u;
        i--;
    }
    for (int u: mul) {
        if (!j) break;
        if (cur_p * u >= h) return -1;
        cur_p *= u;
        j--;
    }
    cout << "cur_p = " << cur_p << endl;
    if (cur_p * k >= h) return true;
    return false;
}

int solve() {
    cout << "solve " << endl;
    cout << "current_p = " << p << endl;
    int ans = n;
    for (int i = 0 ; i <= (int)add.size() ; i++) {
        for (int j = 0 ; j <= (int).size() ; j++) {
            for (int k = 1 ; k <= att ; k++) {
                if (ck(i, j, k)) {
                    ans = min(ans, i + j + k);
                }
            }
        }
    }
    return ans;
} 

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> p >> h;
    for (int i = 0 ; i < n ; i++) {
        char c;
        cin >> c;
        if (c == '!') att++;
        else {
            int x;
            cin >> x;
            if (c == '*') mul.push_back(x);
            else add.push_back(x);
        }
    }
    sort(add.rbegin(), add.rend());
    sort(mul.rbegin(), mul.rend());
    int np = get_new_power();
    if (!att) {
        cout << "*";
        return 0;
    }
    if (p == np) {
        if (p == 0) {
            cout << "*";
            return 0;
        } else {
            int attack_needed = (h + p - 1) / p;
            int full_turn = (attack_needed - 1) / att;
            cout << full_turn * (n - att) + attack_needed;
            return 0;
        }
    }
    int ans = 0;
    while (true) {
        // cout << "p = " << p << endl;
        // cout << "h = " << h << endl;
        int new_p = get_new_power();
        if (new_p == -1) {
            int x = solve();
            ans += x;
            break;
        }
        else if (new_p * att > h) {
            int x = solve();
            ans += x;
            break;
        }
        else {
            h -= new_p * att;
            ans += n;
        }
        p = new_p;
    }
    cout << ans;
}