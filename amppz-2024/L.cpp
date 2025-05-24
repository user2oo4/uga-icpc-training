#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxN = 6e6 + 5;

char ch[] = {'P', 'K', 'N'};

struct Node{
    int child[3];
    int cnt;
} trie[maxN];

int n;
int sz;
string s[100005];
int ans;

bool cmp(string &a, string &b) {
    return a.length() > b.length();
}

void insert(string s) {
    // cout << "s = " << s << endl;
    int cur = 0;
    int len = s.length();
    int i = 0;
    int depth = 0;
    // cout << "s = " << s << endl;
    while (true) {
        // cout << "i = " << i << endl;
        char c = s[i];
        int id = 0;
        if (c == ch[1]) id = 1;
        else if (c == ch[2]) id = 2;
        if (!trie[cur].child[id]) {
            trie[cur].child[id] = ++sz;
        }
        cur = trie[cur].child[id];
        // cout << cur << endl;
        trie[cur].cnt++;
        i++;
        depth++;
        if (i == len) {
            if (trie[cur].cnt == 1) break;
            if (depth > 400000) break;
            i = 0;
        }
    }
}

void dfs(int s) {
    // cout << "cnt " << s << " = " << trie[s].cnt << endl;
    if (trie[s].child[0] && trie[s].child[1] && trie[s].child[2]) {
        ans += trie[trie[s].child[0]].cnt * trie[trie[s].child[1]].cnt * trie[trie[s].child[2]].cnt;
    }
    if (trie[s].child[0]) dfs(trie[s].child[0]);
    if (trie[s].child[1]) dfs(trie[s].child[1]);
    if (trie[s].child[2]) dfs(trie[s].child[2]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> s[i];
        s[i] = s[i] + s[i];
    }
    sort(s, s + n, &cmp);
    for (int i = 0 ; i < n ; i++) {
        insert(s[i]);
    }
    dfs(0);
    cout << ans;
}