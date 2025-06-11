#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a ; i < (b) ; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long double ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxN = 2e5 + 5;
struct Point {
    ll x, y;
    Point (ll x = 0, ll y = 0): x(x), y(y) {}
    Point operator- (Point p)  {return Point(x - p.x, y - p.y);}
    Point operator+ (Point p)  {return Point(x + p.x, y + p.y);}
    Point operator* (ll d)  {return Point(x*d, y*d);}
    Point operator/ (ll d)  {return Point(x/d, y/d);}
    ld dist(Point p) {
        return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
    }
    ll cross(Point p) {
        return x*p.y - y*p.x;
    }
    ll cross(Point a, Point b) {
        return (a-*this).cross(b-*this);
    }
    ll dot(Point p) {
        return x*p.x + y*p.y;
    }
} big[maxN], small[maxN];
int n, m;
ld pf[maxN];
pii intersection_id[maxN][2];
// intersection of edges

ld find_length(int i, int j) {
    // find the perimeter from point i to point j on the polygon
    if (i == j) return 0;
    if (i < j) return pf[j] - pf[i];
    return find_length(i, n) + big[1].dist(big[n]) + find_length(1, j);
}

bool onSegment(Point s, Point e, Point p) {
    // p on se
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

int sgn(ll x) {
    return (x > 0) - (x < 0);
}

vector<Point> lineInter(Point s1, Point e1, Point s2, Point e2) {
    ll d = (e1 - s1).cross(e2 - s2);
    if (d == 0) return {};
    ll p = s2.cross(e1, e2);
    ll q = s2.cross(e2, s1);
    vector<Point> vt;
    vt.push_back((s1 * p + e1 * q) / d);
    return vt;
}

vector<Point> rayInter(Point s1, Point e1, Point s2, Point e2) {
    // check if ray from s1 to e1 lies on segment s2 e2
    auto vt = lineInter(s1, e1, s2, e2);
    if (vt.empty()) return {};
    Point p = vt[0];
    if (onSegment(p, s1, e1) && onSegment(s2, e2, p)) return vt;
    return {};
}

void find_intersections() {
    int sm1 = 1;
    int sm2 = 2;
    int lg1 = 1;
    int lg2 = 2;
    while (true) {
        auto vt = rayInter(small[sm1], small[sm2], big[lg1], big[lg2]);
        if (!vt.empty()) {
            intersection_id[sm1][0] = pii(lg1, lg2);
            // cout << "sm1 sm2 = " << sm1 << " " << sm2 << endl;
            // cout << "lg1 lg2 = " << lg1 << " " << lg2 << endl;
            Point p = vt[0];
            // cout << "p = " << vt[0].x << " " << vt[0].y << endl;
            sm1++; sm2++;
            if (sm2 > m) sm2 -= m;
            if (sm1 > m) break;
        } else {
            lg1++;
            lg2++;
            if (lg1 > n) lg1 -= n;
            if (lg2 > n) lg2 -= n;
        }
    }
    sm1 = 2;
    sm2 = 1;
    while (true) {
        auto vt = rayInter(small[sm1], small[sm2], big[lg1], big[lg2]);
        if (!vt.empty()) {
            // cout << "sm1 sm2 = " << sm1 << " " << sm2 << endl;
            // cout << "lg1 lg2 = " << lg1 << " " << lg2 << endl;
            intersection_id[sm1][1] = pii(lg1, lg2);
            Point p = vt[0];
            // cout << "p = " << vt[0].x << " " << vt[0].y << endl;
            sm1++; sm2++;
            if (sm1 > m) sm1 -= m;
            if (sm2 > m) break;
        } else {
            lg1++;
            lg2++;
            if (lg1 > n) lg1 -= n;
            if (lg2 > n) lg2 -= n;
        }
    }
}

ld ans = 0.0;
void solve() {
    for (int i = 1 ; i <= m ; i++) {
        int i2 = i + 1;
        if (i2 > m) i2 = 1;
        pii it1 = intersection_id[i][0];
        pii it2 = intersection_id[i2][1];
        // swap(it1, it2);
        // cout << "i i2 = " << i << " " << i2 << endl;
        ld dist = find_length(it1.second, it2.first);
        // cout << "length " << it1.second << " " << it2.first << " = " << dist << endl;
        vector<Point> vt1 = rayInter(small[i], small[i2], big[it1.first], big[it1.second]);
        vector<Point> vt2 = rayInter(small[i2], small[i], big[it2.first], big[it2.second]);
        // cout << "vt1 vt2 sz = " << sz(vt1) << " " << sz(vt2) << endl;
        dist += vt1[0].dist(big[it1.second]);
        dist += vt2[0].dist(big[it2.first]);
        // cout << "dist = " << dist << endl;
        ld chance = (pf[n] - dist) / pf[n];
        // cout << "chance = " << chance << endl;
        ans += small[i].dist(small[i2]) * chance;
    }
    cout << fixed << setprecision(15) << ans;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        cin >> big[i].x >> big[i].y;
    }
    for (int i = 1 ; i <= m ; i++) {
        cin >> small[i].x >> small[i].y;
    }
    // prefix distance for big polygon
    for (int i = 1 ; i < n ; i++) {
        pf[i] = big[i + 1].dist(big[i]);
    }
    pf[n] = big[1].dist(big[n]);
    for (int i = 2 ; i <= n ; i++) {
        pf[i] += pf[i - 1];
    }
    // find intersections
    find_intersections();
    // return 0;
    solve();
}