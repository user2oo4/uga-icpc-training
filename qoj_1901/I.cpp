#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) {
    return rng() % (r - l + 1) + l;
}

int n;

void bet() {
    string s;
    cin >> s;
    if (s == "ROUND") {
        int cur_money;
        int bet_money;
        cin >> cur_money >> bet_money;
        if (bet_money * 7 <= cur_money) {
            cout << "PLAY" << endl;
        } else {
            cout << "SKIP" << endl;
        }
    } else exit(0);
}

int simulate(int cur_money) {
    int bet_money = Rand(1, cur_money);
    if (bet_money * 7 <= cur_money * 2) {
        int x = Rand(1, 2);
        if (x == 1) cur_money -= bet_money;
        else cur_money += 2 * bet_money;
        // cout << "bet " << bet_money << endl;
    }
    // cout << "cur_money = " << cur_money << endl;
    return cur_money;
}

signed main() {
    // cin >> n;
    // while (true) {
    //     bet();
    // }
    int tc = 10000;
    int wins = 0;
    while (tc--) {
        int cur_money = 1000;
        bool win = 0;
        for (int i = 1 ; i <= 1000 ; i++) {
            cur_money = simulate(cur_money);
            if (cur_money >= 10000) {
                // cout << "WIN AT ROUND " << i << endl;
                win = 1;
                break;
            } else if (!cur_money) {
                // cout << "LOST AT ROUND " << i << endl;
                break;
            }
        }
        if (cur_money < 10000) {
            // cout << "LOST" << endl;
            // cout << "CUR_MONEY = " << cur_money;
        }
        wins += win;
    }
    cout << "wins = " << wins << endl;
}