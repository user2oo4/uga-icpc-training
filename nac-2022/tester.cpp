#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e9;

int Rand(int l, int r) {
    return rng() % (r - l + 1) + l;
}

void gen_test() {
    int n = 100000;
    int q = 1000;
    ofstream fout("input.txt");
    fout << n << " " << q << endl;
    for (int i = 1 ; i <= n ; i++) {
        int x = Rand(1, inf);
        int y = Rand(1, inf);
        int h = Rand(1, inf);
        fout << x << " " << y << " " << h << endl;
    }
    for (int i = 0; i < q; i++) {
        int x_low = Rand(1, inf);
        int x_high = Rand(x_low, inf);
        int y_low = Rand(1, inf);
        int y_high = Rand(y_low, inf);
        fout << x_low << " " << y_low << " " << x_high << " " << y_high << endl;
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

int main() {
    gen_test();
    return 0;
}
