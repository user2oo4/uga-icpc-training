#include <bits/stdc++.h>
using namespace std;

const int maxN = 3e5 + 5;
int a[maxN];
int pos[maxN];
int n;

int bit[maxN];
void add(int pos, int val) {
    for (int i = pos ; i < maxN ; i += (i & (-i))) bit[i] += val;
}
int sum(int pos) {
    int ans = 0;
    for (int i = pos ; i > 0 ; i -= (i & (-i))) ans += bit[i];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int cur = n;
    while (cur > 1 && pos[cur - 1] < pos[cur]) cur--;
    cout << cur - 1 << " " << cur - 1 << endl;
    for (int i = cur - 1 ; i >= 1 ; i--) {
        add(pos[i], 1);
        int cur_pos = pos[i] + sum(n) - sum(pos[i]);
        cout << cur_pos << " " << 1 << endl;
    }
}
