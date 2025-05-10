#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e18;

int Rand(int l, int r) {
    return rng() % (r - l + 1) + l;
}

void gen_test() {
    int t = 1000;
    ofstream fout("input.txt");
    fout << t << endl;
    for (int i = 1 ; i <= 500 ; i++) {
        int n = Rand(1, inf);
        int d = Rand(1, 5);
        fout << n << " " << d << endl;
    }
    for (int i = 1 ; i <= 500 ; i++) {
        int n = Rand(1, inf);
        int d = Rand(1, inf);
        fout << n << " " << d << endl;
    }
    fout.close();
}

bool compare_files(const string &file1, const string &file2) {
    ifstream f1(file1), f2(file2);
    string line1, line2;
    int line_num = 1;
    
    while (getline(f1, line1) && getline(f2, line2)) {
        if (line1 != line2) {
            cout << "Mismatch at line " << line_num << ":" << endl;
            cout << "A: " << line1 << endl;
            cout << "B: " << line2 << endl;
            return false;
        }
        line_num++;
    }

    // If one file has extra lines
    if (getline(f1, line1) || getline(f2, line2)) {
        cout << "Output sizes differ!" << endl;
        return false;
    }
    
    return true;
}

void run_tester() {
    int test_cases = 100;
    for (int i = 1; i <= test_cases; i++) {
        cout << "Running test " << i << "..." << endl;
        gen_test();

        // Run both programs (A and B) without redirection since they use freopen
        system("A.exe");
        system("B.exe");

        // Compare outputs
        if (!compare_files("output.txt", "answer.txt")) {
            cout << "Test case " << i << " failed!" << endl;
            return;
        }
    }
    cout << "All test cases passed!" << endl;
}

signed main() {
    gen_test();
    return 0;
}
