#include <bits/stdc++.h>
using namespace std;

const int maxN = 1005;
typedef pair<int, int> ii;
int a[maxN][3]; // the board
int n;
ii pos[maxN][3]; // 3 positions of a color (row, 0/1/2)
bool done[maxN];
int cnt[maxN];
int balls[maxN]; // current number of balls in a row
// 0, 1, 2 || 0, 1 || 0
vector<int> not_full;
int current_empty;
vector<ii> ans;

void output() {
    for (int i = 1 ; i <= n + 1 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

void move(int fr, int to) {
    // this shouldn't happen
    // cout << "move " << fr << " " << to << endl;
    if (balls[to] == 3 || balls[fr] == 0) {
        cout << "bruh";
        exit(0);
    }
    if (to == fr) {
        return;
    }
    ans.push_back(ii(fr, to));
    // move from row fr to row to
    int col = a[fr][balls[fr] - 1]; // the color to be moved
    int id = 0;
    for (int i = 0 ; i < 3 ; i++) {
        if (pos[col][i].first == fr && pos[col][i].second == balls[fr] - 1) {
            id = i;
            break;
        }
    }
    // pos[col][id]: current position (fr, balls[fr] - 1)
    ii new_pos = ii(to, balls[to]);
    pos[col][id] = new_pos;
    a[fr][balls[fr] - 1] = 0;
    balls[fr]--;
    a[to][balls[to]++] = col;
    // output();
}

void clear_column() {
    // make sure there is one empty column
    not_full.clear();
    for (int i = 1 ; i <= n + 1 ; i++) {
        if (balls[i] < 3) not_full.push_back(i);
    }
    if (not_full.size() == 3) {
        // 3 columns of 2
        move(not_full[0], not_full[1]);
        move(not_full[0], not_full[2]);
        current_empty = not_full[0];
    } else if (not_full.size() == 2) {
        // one 1, one 2
        if (balls[not_full[0]] == 1) {
            move(not_full[0], not_full[1]);
            current_empty = not_full[0];
        } else {
            move(not_full[1], not_full[0]);
            current_empty = not_full[1];
        }
    } else {
        current_empty = not_full[0];
    }
}

void solve(int x) {
    // cout << "solve " << x << endl;
    // solve a color
    // assume that there is an empty column
    // move that color to that empty column
    if (pos[x][1].second < pos[x][2].second) swap(pos[x][1], pos[x][2]);
    if (pos[x][0].second < pos[x][1].second) swap(pos[x][0], pos[x][1]);
    if (pos[x][1].second < pos[x][2].second) swap(pos[x][1], pos[x][2]);
    // now pos[x][0] > pos[x][1] > pos[x][2]
    vector<int> can;
    for (int i = 0 ; i < 3 ; i++) {
        int cur_col = pos[x][i].first;
        // cout << "cur_col = " << cur_col << endl;
        // cout << "top = " << a[cur_col][balls[cur_col] - 1] << endl;
        bool ok = false;
        while(a[cur_col][balls[cur_col] - 1] != x) {
            move(cur_col, can.back());
            can.pop_back();
        }
        move(cur_col, current_empty);
        for (int j = balls[cur_col] ; j < 3 ; j++) {
            can.push_back(cur_col);
            // cout << "can " << cur_col << endl;
        }
    }
    clear_column();
    done[x] = 1;
    // cout << "solve " << x << " done " << endl;
    // output();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    cin >> n;
    for (int i = 1 ; i <= n + 1 ; i++) {
        bool no_full = false;
        for (int j = 0 ; j < 3 ; j++) {
            cin >> a[i][j];
            if (!a[i][j]) {
                no_full = true;
                continue;
            }
            balls[i]++;
            pos[a[i][j]][cnt[a[i][j]]++] = ii(i, j);
        }
        if (no_full) not_full.push_back(i);
    }
    clear_column();
    for (int i = 1 ; i <= n ; i++) {
        done[i] = 0;
    }
    for (int w = 1 ; w <= n ; w++) {
        for (int i = 1 ; i <= n ; i++) {
            if (!done[a[i][2]] && pos[a[i][2]][0].second + pos[a[i][2]][1].second + pos[a[i][2]][2].second > 2) {
                solve(a[i][2]);
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (ii tmp: ans) {
        cout << tmp.first << ' ' << tmp.second << endl;
    }
    // output();
}