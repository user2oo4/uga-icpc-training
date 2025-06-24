#include <bits/stdc++.h>
using namespace std;

int n;
int k;

vector<string> codes;
vector<string> br;
vector<string> ans;

void bck(string s) {
    if (s.length() == k) {
        codes.push_back(s);
        return;
    }
    for (int i = 0 ; i < 10 ; i++) {
        char c = '0' + i;
        bck(s + c);
    }
}

bool ck(string s1, string s2) {
    // check if s1 is in s2
    int i1 = 0;
    for (int i = 0 ; i < s2.length() ; i++) {
        if (s2[i] == s1[i1]) {
            i1++;
            if (i1 == (int)s1.length()) return true;
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> k >> n;
    for (int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        br.push_back(s);
    }
    bck("");
    for (string s1: codes) {
        bool ok = true;
        for (string s2: br) {
            if (!ck(s1, s2)) {
                ok = false;
                break;
            }
        }
        if (ok) ans.push_back(s1);
    }
    cout << (int)ans.size() << endl;
    for (string s: ans) cout << s << endl;
}