#include <bits/stdc++.h>
using namespace std;
#define int long long

int numberOfDivisors(int num) {
    int total = 1;
    for (int i = 2; (int)i * i <= num; i++) {
        if (num % i == 0) {
            int e = 0;
            do {
                e++;
                num /= i;
            } while (num % i == 0);
            total *= e + 1;
        }
    }
    if (num > 1) {
        total *= 2;
    }
    return total;
}

int nthRoot(int n, int m) {
    if (n == 1) {
        return m;
    }    
    int low = 1LL;
    int high = m;
    int mid;
    int ans = -1;
    while (low <= high) {
        // cout << "l r " << low << " " << high << endl;
        mid = (low + high) / 2;
        int x = mid;
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (x > m / mid) {
                ok = false;
                break;
            }
            x *= mid;
        }
        if (!ok) {
            high = mid - 1;
            continue;
        }
        if (x == m * 1LL) {
            ans = mid;
            break;
        } else if (x > m)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int x;
    cin >> x;
    int ans = -1;
    if (x == 1) {
        cout << 1;
        return 0;
    }
    for (int i = 60 ; i >= 2 ; i--) {
        int a = nthRoot(i, x);
        if (a == -1) continue;
        else if (numberOfDivisors(a) == i) {
            ans = a;
        }
        // cout << "i = " << i << endl;
        // cout << "a = " << a << endl;
        // cout << "countDiv = " << numberOfDivisors(a) << endl;
    }
    cout << ans;
}