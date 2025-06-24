#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> nums;
int n;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}


int cheese() {

    int k = n / 2;
    vector<int> left_sums, right_sums;

    for (int mask = 0; mask < (1 << k); ++mask) {
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            if (mask & (1 << i)) sum += nums[i];
        }
        left_sums.push_back(sum);
    }

    sort(left_sums.begin(), left_sums.end());
    for (int i = 1; i < (int)left_sums.size(); ++i) {
        if (left_sums[i] == left_sums[i - 1]) return left_sums[i];
    }

    for (int mask = 0; mask < (1 << (n - k)); ++mask) {
        int sum = 0;
        for (int i = 0; i < n - k; ++i) {
            if (mask & (1 << i)) sum += nums[k + i];
        }
        right_sums.push_back(sum);
    }

    sort(right_sums.begin(), right_sums.end());
    for (int i = 1; i < (int)right_sums.size(); ++i) {
        if (right_sums[i] == right_sums[i - 1]) return right_sums[i];
    }

    int i = 1, j = 1;
    while (i < (int)left_sums.size() && j < (int)right_sums.size()) {
        if (left_sums[i] == right_sums[j]) return left_sums[i];
        if (left_sums[i] < right_sums[j]) ++i;
        else ++j;
    }

    left_sums.clear();
    right_sums.clear();
    sort(nums.begin(), nums.end());
    for (int mask = 0; mask < (1 << k); ++mask) {
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            if (mask & (1 << i)) sum += nums[i];
        }
        left_sums.push_back(sum);
    }

    sort(left_sums.begin(), left_sums.end());
    for (int i = 1; i < (int)left_sums.size(); ++i) {
        if (left_sums[i] == left_sums[i - 1]) return left_sums[i];
    }

    for (int mask = 0; mask < (1 << (n - k)); ++mask) {
        int sum = 0;
        for (int i = 0; i < n - k; ++i) {
            if (mask & (1 << i)) sum += nums[k + i];
        }
        right_sums.push_back(sum);
    }

    sort(right_sums.begin(), right_sums.end());
    for (int i = 1; i < (int)right_sums.size(); ++i) {
        if (right_sums[i] == right_sums[i - 1]) return right_sums[i];
    }

    i = 1; j = 1;
    while (i < (int)left_sums.size() && j < (int)right_sums.size()) {
        if (left_sums[i] == right_sums[j]) return left_sums[i];
        if (left_sums[i] < right_sums[j]) ++i;
        else ++j;
    }

    unordered_map<int, int> seen;
    while (true) {
        int sum = 0;
        int mask = rng();
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) sum += nums[i];
        }
        if (seen.count(sum)) return sum;
        seen[sum] = 1;
    }

    return -1;
}

int find_sum() {
    int total = pow(3, n);
    for (int mask = 0; mask < total; ++mask) {
        int sum1 = 0, sum2 = 0, cnt1 = 0, cnt2 = 0;
        int x = mask;
        for (int i = 0; i < n; ++i) {
            int group = x % 3;
            if (group == 1) { sum1 += nums[i]; cnt1++; }
            else if (group == 2) { sum2 += nums[i]; cnt2++; }
            x /= 3;
        }
        if (cnt1 > 0 && cnt2 > 0 && sum1 == sum2) {
            return sum1;
        }
    }
    return -1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    nums.assign(n, 0);
    for (int i = 0 ; i < n ; i++) cin >> nums[i];
    if (n < 15) {
        cout << find_sum();
        return 0;
    }
    cout << cheese();
}