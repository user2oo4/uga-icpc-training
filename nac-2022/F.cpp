#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int maxN = 17;
const int maxT = 105;
const ld eps = 1e-9;

int n, T;
int r[maxN + 5], s[maxN + 5];
ld prob[maxN + 5];

ld exp_sol[maxT][maxN + 5];
ld exp_mask[maxT][(1 << maxN) + 5];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> T;
    for (int i = 0 ; i < n ; i++) {
        cin >> r[i] >> s[i] >> prob[i];
    }
    exp_mask[0][0] = 1;
    for (int t = 0 ; t <= T ; t++) {
        if (t) {
            for (int i = 0 ; i < n ; i++) {
                exp_sol[t][i] += exp_sol[t - 1][i];
            }
        }
        for (int mask = 0 ; mask < (1 << maxN) ; mask++) {
            ld total_solve = 0.0;
            int unsolved = 0;
            for (int i = 0 ; i < n ; i++) {
                if (!(mask & (1 << i))) {
                    total_solve += exp_sol[t][i];
                    unsolved++;
                }
            }
            bool zero = (total_solve < eps);
            for (int i = 0 ; i < n ; i++) {
                if (!(mask & (1 << i))) {
                    ld ratio = 1.0 / unsolved;
                    if (!zero) ratio = exp_sol[t][i] / total_solve;
                    if (t + r[i] <= T) {
                        exp_mask[t + r[i]][mask ^ (1 << i)] 
                        += (exp_mask[t][mask] * (1 - prob[i]) * ratio);
                    }
                    if (t + r[i] + s[i] <= T) {
                        exp_mask[t + r[i] + s[i]][mask ^ (1 << i)]
                        += (exp_mask[t][mask] * prob[i] * ratio);
                        exp_sol[t + r[i] + s[i]][i]
                        += (exp_mask[t][mask] * prob[i] * ratio);
                    }
                }
            }  
        }
    }
    for (int i = 0 ; i < n ; i++) {
        cout << fixed << setprecision(9) << exp_sol[T][i] << endl;
    }
}