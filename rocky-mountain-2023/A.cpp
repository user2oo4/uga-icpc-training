#include <bits/stdc++.h>
using namespace std;

int n;
string prv = "";
string nxt = "";
int cnt;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0 ; i <= n ; i++) {
        if (i == n) nxt = "...";
        else cin >> nxt;
        if (i && nxt != "Present!" && prv != "Present!") {
            cout << prv << endl;
            cnt++;
        }
        prv = nxt;
    }
    if (!cnt) cout << "No Absences";
}  