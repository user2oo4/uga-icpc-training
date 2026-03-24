#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<ii> pt;
#define x first
#define y second

const int maxN = 101;
pt p1[maxN];
pt p2[maxN];

int orientation(pt p, pt q, pt r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // collinear
    if (val > 0) return 1; // cw
    if (val < 0) return 2; // cc2
}

bool onSegment(pt a, pt b, pt c) {
    // has to be completely in btw
    // check if b is on ac if abc is collinear
    if (b.x < max(a.x, c.x) && b.x > min(a.x, c.x)
    &&  b.y < max(a.y, c.y) && b.y > min(a.y, c.y)) {
        return true;
    }
    return false;
}

bool Intersect(pt p1, pt q1, pt p2, pt q2) {
    // check if p1q1 and p2q2 intersects
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4) return true;
    
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> p1[i].x >> p1[i].y >> p2[i].x >> p2[i].y;
    }
    
}