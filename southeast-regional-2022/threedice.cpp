#include <bits/stdc++.h>
using namespace std;

const int maxN = 1005;
int n;
string word[maxN];
int col[30];
set<int> S;
int ch[20];
int cnt[4];
bool has[4];
vector<int> dice[4];
int sz;
bool found = false; // Flag to indicate if a solution has been found

bool check() {
    for (int i = 0; i < n; i++) {
        memset(has, false, sizeof(has));
        for (int j = 0; j < 3; j++) {
            if (col[word[i][j] - 'a']) {
                if (has[col[word[i][j] - 'a']]) return false;
                has[col[word[i][j] - 'a']] = true;
            }
        }
    }
    return true;
}

void answer() {
    if (!check()) return;
    for (int i = 0; i < 26; i++) {
        if (col[i]) {
            dice[col[i]].push_back(i);
        }
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < 26; j++) {
            if (dice[i].size() == 6) break;
            if (!col[j]) {
                col[j] = i;
                dice[i].push_back(j);
            }
        }
    }
    found = true; // Set the flag when a solution is found
}

void solve(int id) {
    if (found) return; // Stop further recursion if solution has been found
    if (id == sz) {
        answer();
        return;
    }
    for (int color = 1; color <= 3; color++) {
        if (cnt[color] == 6) continue;
        col[ch[id]] = color;
        cnt[color]++;
        solve(id + 1);
        cnt[color]--;
        col[ch[id]] = 0;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word[i];
        // cout << "word " << i << " = " << word[i] << endl;
        S.insert(word[i][0] - 'a');
        S.insert(word[i][1] - 'a');
        S.insert(word[i][2] - 'a');
    }
    if (S.size() > 18) {
        cout << 0;
        return 0;
    }
    for (int c: S) {
        ch[sz++] = c;
        // cout << c << endl;
    }
    // cout << "sz = " << sz << endl;
    solve(0);
    // cout << "found = " << found << endl;
    if (found) {
        for (int i = 1; i <= 3; i++) {
        for (int j: dice[i]) {
            cout << (char)(j + 'a');
        }
        cout << ' ';
    }
    cout << endl;
    }
    if (!found) cout << 0;
}