#include <bits/stdc++.h>
using namespace std;

string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ ";
string str;

string emoji[10] = {":)", ":-)", ":-(", ";-)", "xD", "^_^"
, "-_-", "^o^", "^^;", "(..)"};

int get_length(string s) {
    int len = s.length();
    int ans = 0;
    for (int i = 0 ; i < len ; i++) {
        ans++;
        for (int j = 0 ; j < 10 ; j++) {
            if (i + emoji[j].length() - 1 < len) {
                if (s.substr(i, emoji[j].length()) == emoji[j]) {
                    i += emoji[j].length() - 1;
                    break;
                }
            }
        }
    }
    return ans;
}

string replace(char c1, char c2) {
    string ans = "";
    for (int i = 0 ; i < str.length() ; i++) {
        if (str[i] == c1) ans += c2;
        else ans += str[i];
    }
    return ans;
}

signed main() {
    // freopen("output.txt", "w", stdout);
    getline(cin, str);
    int sz = alphabet.length();
    int mn = str.length() + 1;
    int mx = 0;
    for (int i = 0 ; i < sz ; i++) {
        for (int j = 0 ; j < sz ; j++) {
            string s = replace(alphabet[i], alphabet[j]);
            int l = get_length(s);
            mn = min(mn, l);
            mx = max(mx, l);
        }
    }
    cout << mn << " " << mx;
}
