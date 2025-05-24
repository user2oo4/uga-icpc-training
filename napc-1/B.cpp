#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    bool operator!=(P p) const { return tie(x,y)!=tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x−axis in interval [−pi , pi ]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes d i s t ()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated ’a ’ radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); 
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; 
    }
};

typedef Point<ll> P;
vector<P> convexHull(vector<P> pts) {
    if (sz(pts) <= 1) return pts;
    // sort(all(pts));
    vector<P> h(sz(pts)+1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (P p : pts) {
            while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
                h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

int n;
int tc;

int get_sum(vector<int> &pf, int l, int r) {
    // get the number of points from l to r
    // cnt[l] to cnt[r - 1]
    // cout << "get sum " << l << " " << r << endl;
    int sz = sz(pf);
    if (l <= r) {
        // cout << "sum " << l << " " << r << " = " << pf[r] - (l? pf[l - 1]: 0) + (r - l + 1) << endl;
        return pf[r] - (l? pf[l - 1]: 0) + (r - l + 1);
    }
    else return get_sum(pf, l, sz - 1) + get_sum(pf, 0, r);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tc;
    while (tc--) {
        cin >> n;
        cout << "n = " << n << endl;
        vector<P> pts;
        vector<int> cnt(n, 0);
        vector<int> pf(n, 0);
        for (int i = 1 ; i <= n ; i++) {
            ll x, y;
            cin >> x >> y;
            pts.push_back(P(x, y));
        }
        pts.push_back(P(0, 0));
        sort(all(pts));
        vector<P> cvh = convexHull(pts);
        sort(all(cvh));
        for (P p: cvh) cout << p.x << " " << p.y << endl;
        for (P p: pts) cout << p.x << " " << p.y << endl;
        bool ok = false;
        int i1 = 0;
        for (int i = 0 ; i < sz(cvh) ; i++) {
            if (cvh[i].x == 0 && cvh[i].y == 0) {
                ok = true; break;
            }
            int id = i - 1;
            if (id < 0) id = sz(cvh) - 1;
            while (pts[i1] != cvh[i]) {
                if (pts[i1].x != 0 || pts[i1].y != 0) {
                    cnt[id]++;
                }
                i1++;
                if (i1 >= sz(pts)) break;
            }
            i1++;
            cout << "i i1 = " << i << " " << i1 << endl;
            if (i1 >= sz(pts)) break;
        }
        for (int i = 0 ; i < sz(cvh) ; i++) {
            cout << "cnt " << i << " = " << cnt[i] << endl;
            if (!i) pf[0] = cnt[0];
            else pf[i] = pf[i - 1] + cnt[i];
        }
        if (ok) {
            cout << 0 << endl;
            continue;
        }
        int ans = n;
        for (int i = 0 ; i < sz(cvh) ; i++) {
            int l = 1;
            int r = sz(cvh) - 1;
            cout << "i = " << i << endl;
            while (l < r) {
                int mid = (l + r) / 2;
                int i1 = i + 1;
                int i2 = i + mid;
                if (i1 >= sz(cvh)) i1 -= sz(cvh);
                if (i2 >= sz(cvh)) i2 -= sz(cvh);
                cout << "i2 = " << i2 << endl;
                if (cvh[i].cross(P(0, 0), cvh[i2]) * cvh[i].cross(P(0, 0), cvh[i1]) > 0) l = mid + 1;
                else r = mid;
            }
            int i1 = i + l;
            if (i1 >= sz(cvh)) i1 -= sz(cvh);
            int i2 = i1 - 1;
            if (i2 < 0) i2 += sz(cvh);
            cout << "i i1 i2 " << i << " " << i1 << " " << i2 << endl;
            int ans1 = n - get_sum(pf, i1, i);
            int ans2 = n - get_sum(pf, i, i2);
            cout << "ans1 ans2 " << ans1 << " " << ans2 << endl;
            ans = min(ans, ans1);
            ans = min(ans, ans2);
        }
        cout << ans << endl;
    }
}