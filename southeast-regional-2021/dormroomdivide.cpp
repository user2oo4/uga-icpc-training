#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const int maxN = 2e5 + 5;
const ld eps = 1e-12;
int n;

struct Point {
    ld x, y;
    explicit Point(ld x = 0, ld y = 0): x(x), y(y) {}
} pt[maxN];

ld cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

ld polygonArea(vector<Point>& v) {
    if (v.size() < 3) return 0;
    // for (Point p: v) cout << p.x << " " << p.y << endl;
    ld a = cross(v.back(), v[0]);
    for (int i = 0 ; i < (int)v.size() - 1 ; i++) {
        a += cross(v[i], v[i + 1]);
    }
    // cout << "area = " << a << endl;
    return a;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> pt[i].x >> pt[i].y;
    }
    vector<Point> left, right;
    int L = 1;
    int R = n;
    while (L < R) {
        int mid = (L + R + 1) / 2;
        // cout << "mid = " << mid << endl;
        left.clear(); right.clear();
        for (int i = 1 ; i <= mid ; i++) {
            left.push_back(pt[i]);
        }
        for (int i = mid ; i <= n ; i++) {
            right.push_back(pt[i]);
        }
        right.push_back(pt[1]);
        ld area_l = polygonArea(left);
        ld area_r = polygonArea(right);
        // cout << "mid = " << mid << endl;
        // cout << "area_l area_r = " << area_l << " " << area_r << endl;
        if (area_l < area_r) L = mid;
        else R = mid - 1;
    }

    // between i and i + 1
    // cout << "L = " << L << endl;
    Point l = pt[L];
    Point r = pt[L + 1];
    Point mid;
    while (abs(r.x - l.x + r.y - l.y) > eps) {
        mid.x = (l.x + r.x) / 2.0;
        mid.y = (l.y + r.y) / 2.0;
        left.push_back(mid);
        right.push_back(mid);
        ld area_l = polygonArea(left);
        ld area_r = polygonArea(right);
        // cout << "mid = " << mid.x << " " << mid.y << endl;
        // cout << fixed << setprecision(10) << "area " << area_l << " " << area_r << endl;
        if (abs(area_r - area_l) < eps) {
            break;
        }
        if (area_l < area_r) l = mid;
        else r = mid;
        left.pop_back();
        right.pop_back();
    }
    cout << fixed << setprecision(10) << mid.x << ' ' << mid.y;
}