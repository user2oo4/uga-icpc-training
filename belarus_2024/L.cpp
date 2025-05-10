#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;

const int maxN = 1e5 + 5;
int n;
int a[maxN];
int cnt7487;
int cnt269[3];
int cnt2[3];
vector<int> ans;

void print_ans() {
    cout << (int)ans.size() << endl;
    for (int u: ans) cout << u << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        if (a[i] == 7487) cnt7487++;
        else if (a[i] % 269 == 0) {
            a[i] /= 269;
            if (a[i] == 1) cnt269[0]++;
            else if (a[i] == 2) cnt269[1]++;
            else if (a[i] == 4) cnt269[2]++;
            else if (a[i] == 8) cnt269[3]++;
        } else {
            if (a[i] == 1) cnt2[0]++;
            else if (a[i] == 2) cnt2[1]++;
            else if (a[i] == 4) cnt2[2]++;
            else if (a[i] == 8) cnt2[3]++;
        }
    }
    if (!cnt7487) {
        cout << 0;
        return 0;
    }
    ans.push_back(7487);
    if (cnt269[3]) {
        ans.push_back(269 * 8);
        print_ans();
        return 0;
    }
    if (cnt269[2]) {
        if (cnt2[1]) {
            ans.push_back(2);
            ans.push_back(269 * 4);
            print_ans();
            return 0;
        }
    }
    if (cnt269[1]) {
        if (cnt2[2]) {
            ans.push_back(4);
            ans.push_back(269 * 2);
            print_ans();
            return 0;
        }
        if (cnt2[1] >= 2) {
            ans.push_back(2);
            ans.push_back(2);
            ans.push_back(269 * 2);
            print_ans();
            return 0;
        }
    }
    if (cnt269[0]) {
        if (cnt2[3]) {
            ans.push_back(8);
            ans.push_back(269);
            print_ans();
            return 0;
        }
        if (cnt2[2] && cnt2[1]) {
            ans.push_back(2);
            ans.push_back(4);
            ans.push_back(269);
            print_ans();
            return 0;
        }
        if (cnt2[1] >= 3) {
            ans.push_back(2);
            ans.push_back(2);
            ans.push_back(2);
            ans.push_back(269);
            print_ans();
            return 0;
        }
    }
    cout << 0 << endl;
}