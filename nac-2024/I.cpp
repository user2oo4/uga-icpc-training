#include <bits/stdc++.h>
using namespace std;

bool vis[41][41][401][2501];
int n, k;
string s;

bool dfs(int p, int cN, int cA, int cC) {
    if (cC > k) return false;
    if (p == n) {
        if (cC == k) {
            cout << s;
            exit(0);
        } else return false;
    }
    if (s[p] != '?') {
        if (s[p] == 'N') {
            dfs(p + 1, cN + 1, cA, cC);
        } else if (s[p] == 'A') {
            dfs(p + 1, cN, cA + cN, cC);
        } else if (s[p] == 'C') {
            dfs(p + 1, cN, cA, cC + cA);
        } else {
            dfs(p + 1, cN, cA, cC);
        }
    } else {
        s[p] = 'N';
        dfs(p + 1, cN + 1, cA, cC);
        s[p] = 'A';
        dfs(p + 1, cN, cA + cN, cC);
        s[p] = 'C';
        dfs(p + 1, cN, cA, cC + cA);
        s[p] = 'X';
        dfs(p + 1, cN, cA, cC);
        s[p] = '?';
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> k;
    cin >> s;
    if (!dfs(0, 0, 0, 0)) {
        cout << -1;
    }
}