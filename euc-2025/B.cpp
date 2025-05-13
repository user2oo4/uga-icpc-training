#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxN = 1e5 + 5;
int n;

vector<int> full;
vector<int> single;
vector<int> nxt;
vector<vector<int>> ans;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    int num = 1ll * 2025 * 2024 / 2;
    int sum = 0;
    for (int i = 1 ; i <= 2025 ; i++) {
        if (n > (num * i * (i + 1) / 2)) continue;
        else {
            n -= (num * i * (i - 1) / 2);
            full.push_back(i);
            sum += i;
            break;
        }
    }
    // cout << "sum = " << sum << endl;
    int sum_nxt = 0;
    while (sum && n > sum && sum_nxt < 2025) {
        for (int i = 2 ; i <= 2025 ; i++) {
            if (n > (sum * i * (i + 1) / 2)) continue;
            else {
                i = min(i, 2025 - sum_nxt);
                n -= (sum * i * (i - 1) / 2);
                nxt.push_back(i);
                sum_nxt += (i + 1);
                break;
            }
        }
    }
    while (n) {
        // cout << "n = " << n << endl;
        for (int i = 2 ; i <= 2025 ; i++) {
            if (n > (i * (i + 1) / 2) && i < 2025) continue;
            else {
                n -= (i * (i - 1) / 2);
                single.push_back(i);
                break;
            }
        }
    }
    for (int u: full) {
        for (int i = 1 ; i <= u ; i++) {
            ans.push_back(vector<int>(1, 2025));
        }
    }
    ans.push_back(nxt);
    ans.push_back(vector<int>(1, 0));
    int cur = 0;
    vector<int> vt;
    vt.clear();
    for (int u: single) {
        // cout << "u = " << u << endl;
        if (cur + u > 2025) {
            // cout << "vt: " << endl;
            // for (int u: vt) cout << u << " ";
            // cout << endl;
            ans.push_back(vt);
            ans.push_back(vt);
            ans.push_back(vector<int>(1, 0));
            cur = 0;
            vt.clear();
        }
        vt.push_back(u);
        cur += u;
    }
    // cout << "vt: " << endl;
    // for (int u: vt) cout << u << " ";
    // cout << endl;
    ans.push_back(vt);
    ans.push_back(vt);
    cout << (int)ans.size() << " " << 2025 << endl;
    for (vector<int> vt: ans) {
        int cur = 0;
        for (int u: vt) {
            // cout << "u = " << u << endl;
            for (int i = 0 ; i < u ; i++) cout << '#';
            cur += u;
            if (cur < 2025) {
                cout << '.';
                cur++;
            }
        }
        for (int i = cur ; i < 2025 ; i++) {
            cout << '.';
        }
        cout << endl;
    }
}