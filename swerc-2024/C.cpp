#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

static constexpr size_t MAX_N = 1005;

// dp[i][j] represents the longest shortest prefix of T matched by
// a glob of length j that matches the first i characters of S
static int dp[MAX_N][MAX_N];

static size_t Z[MAX_N];

static void run_Z(string_view str) {
    memset(Z, 0, str.size() * sizeof(Z[0]));

    size_t l = 0, r = 0;
    for (size_t i = 1; i < str.size(); i++) {
        if (i <= r) {
            Z[i] = min(r - i + 1, Z[i - l]);
        }
        while (i + Z[i] < str.size() && str[Z[i]] == str[i + Z[i]]) {
            Z[i]++;
        }
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
}

int main() {
    size_t N, M;
    string S, T;
    cin >> N >> M >> S >> T;

    memset(dp, -1, sizeof(dp));

    size_t ans = N;

    N++; M++;
    string J = S + '$' + T + '$';

    for (size_t i = 0; i < N; i++) {
        // A single glob
        dp[i][1] = 0;
        
        if (string_view(S).substr(0, i) == string_view(T).substr(0, i)) {
            dp[i][i + 1] = max(dp[i][i + 1], (int)i);
        } else {
            // If the prefix of S and T are different, a possible solution is S[0..i-1]+'*'
            ans = min(ans, i + 1);
        }

        run_Z(string_view(J).substr(i));
        memmove(Z, Z + N - i, M * sizeof(Z[0]));

        for (size_t j = 0; j < N; j++) {
            if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (dp[i][j] == -1) continue;
            size_t pref = dp[i][j]; // The shortest prefix of T matched by the glob

            // We try to extend the glob with S[i..i+x]+'*', we can find the first position
            // k such that the glob match T[0..k+x] by using Z algorithm, and then update
            // dp[i+x][j+x+1] with new prefix
            size_t k = pref;
            for (size_t x = 1; i + x <= N; x++) {
                while (k < M && Z[k] < x) k++;

                if (i + x == N) {
                    // We have matched the whole S, we can't extend the glob anymore.
                    // Since we added a '$' at the end of S, the only possible way to match
                    // T is to match the whole string. Otherwise, we have a possible solution.
                    if (k == M) {
                        // Note that we need to remove the '$' from the answer.
                        ans = min(ans, j + x - 1);
                    }
                    break;
                }

                if (k == M) {
                    // We have matched the whole T, a possible solution is S[0..i+x]+'*'
                    ans = min(ans, j + x + 1);
                }
                size_t new_pref = j + x + 1;
                dp[i + x][new_pref] = max(dp[i + x][new_pref], (int)(k + x));
            }
        }
    }

    cout << ans << endl;

    return 0;
}