#include <bits/stdc++.h>
using namespace std;

const int maxN = 202;
int n;
vector<int> a;
vector<int> b;

int get_ans(vector<int> &vt) {
    cout << "? ";
    vector<bool> ok(n, 0);
    for (int u: vt) ok[u] = 1;
    for (int i = 0 ; i < n ; i++) cout << ok[i];
    cout << endl;
    int x;
    cin >> x;
    return x;
}

void return_ans(int x) {
    cout << "! " << x << endl;
    exit(0);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    a.push_back(0);
    for (int i = 1 ; i < n ; i++) b.push_back(i);
    while (!b.empty()) {
        int ans_a = get_ans(a);
        if (!ans_a) return_ans(0);
        int l = 0;
        int r = (int)b.size() - 1;
        int edge = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            // cout << "l r " << l << " " << r << endl;
            // cout << "mid = " << mid << endl;
            vector<int> part_b(b.begin(), b.begin() + mid + 1);
            // for (int u: part_b) cout << u + 1 << " ";
            // cout << endl;
            int ans_b = get_ans(part_b);
            for (int u: a) part_b.push_back(u);
            int ans_ab = get_ans(part_b);
            if (ans_a + ans_b > ans_ab) {
                r = mid - 1;
                edge = mid;
            } else l = mid + 1;
        }
        // cout << "edge = " << b[edge] + 1 << endl;
        a.push_back(b[edge]);
        b.erase(b.begin() + edge);
    }
    return_ans(1);
}