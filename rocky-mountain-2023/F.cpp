#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
vector<ii> ans;

string str;
int n;
unordered_map<string, int> M;

bool win(string s) {
    // see if string s is winning
    // return false;
    if (M[s]) {
        if (M[s] == 1) return true;
        else return false;
    }
    for (int i = 0 ; i < n - 1 ; i++) {
        if ((s[i] == 'B' && s[i + 1] == 'W') || (s[i] == 'W' && s[i + 1] == 'B')) {
            string new_s = s.substr(0, i) + '.' + s[i] + s.substr(i + 2, n - i - 1);
            if (!win(new_s)) {
                M[s] = 1;
                return true;
            }
            new_s = s.substr(0, i) + s[i + 1] + '.' + s.substr(i + 2, n - i - 1);
            if (!win(new_s)) {
                M[s] = 1;
                return true;
            }
        }
    }
    M[s] = 2;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    cin >> str;
    for (int i = 0 ; i < n - 1 ; i++) {
        if ((str[i] == 'B' && str[i + 1] == 'W') || (str[i] == 'W' && str[i + 1] == 'B')) {
            string new_str = str.substr(0, i) + '.' + str[i] + str.substr(i + 2, n - i - 1);
            // cout << new_str << endl;
            if (!win(new_str)) {
                ans.push_back(ii(i, i + 1));
            }
            new_str = str.substr(0, i) + str[i + 1] + '.' + str.substr(i + 2, n - i - 1);
            // cout << new_str << endl;
            if (!win(new_str)) {
                ans.push_back(ii(i + 1, i));
            }
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (ii tmp: ans) {
        cout << tmp.first + 1 << " " << tmp.second + 1 << endl;
    }
}