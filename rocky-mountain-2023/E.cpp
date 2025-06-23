#include <bits/stdc++.h>
using namespace std;

const int maxN = 1005;

struct Event {
    int time;
    int car_id;
    bool side; // L or R (0 / 1)
    bool type;
    bool br; // pump a or b (0, 1)
    // 0: arrive, 1: finish
    Event(int _time, int _car, bool _side, bool _type): time(_time), car_id(_car), side(_side), type(_type), br(0) {};
    
    Event(int _time, int _car, bool _side, bool _type, bool _br): time(_time), car_id(_car), side(_side), type(_type), br(_br) {};
    bool operator<(const Event& other) const {
        if (time != other.time) return time > other.time;
        if (type != other.type) return type < other.type;
        return br < other.br;
    }
};

priority_queue<Event> pq;

struct Pump {
    int have_a = 0;
    int have_b = 0;
    queue<int> q; // queue of car ids waiting in this line
} P[11][2];

int p, n;
int pump[maxN];
int filling_time[maxN];
int ans[maxN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> p >> n;
    for (int i = 1 ; i <= n ; i++) {
        int t;
        char c;
        cin >> t >> filling_time[i] >> c;
        pq.push(Event(t, i, (c == 'R'), 0));
    }
    while (!pq.empty()) {
        Event tmp = pq.top();
        // cout << "tmp = " << tmp.time << " " << tmp.car_id << " " << tmp.type << " " << tmp.side << endl;
        pq.pop();
        if (tmp.type) {
            // leaving
            int pump_id = pump[tmp.car_id];
            ans[tmp.car_id] = tmp.time;
            if (P[pump_id][tmp.side].have_b == tmp.car_id) {
                P[pump_id][tmp.side].have_b = 0;
            }
            else {
                P[pump_id][tmp.side].have_a = 0;
            }
            if (!P[pump_id][tmp.side].q.empty()) {
                int new_car_id = P[pump_id][tmp.side].q.front();
                if (!P[pump_id][tmp.side].have_a) {
                    if (!P[pump_id][tmp.side].have_b) {
                        P[pump_id][tmp.side].have_b = new_car_id;
                        P[pump_id][tmp.side].q.pop();
                        pq.push(Event(tmp.time + filling_time[new_car_id], new_car_id, tmp.side, 1, 1));
                        if (!P[pump_id][tmp.side].q.empty()) {
                            int nxt_car_id = P[pump_id][tmp.side].q.front();
                            P[pump_id][tmp.side].q.pop();
                            P[pump_id][tmp.side].have_a = nxt_car_id;
                            pq.push(Event(tmp.time + filling_time[nxt_car_id], nxt_car_id, tmp.side, 1, 0));
                        }
                    } else {
                        P[pump_id][tmp.side].have_a = new_car_id;
                        P[pump_id][tmp.side].q.pop();
                        pq.push(Event(tmp.time + filling_time[new_car_id], new_car_id, tmp.side, 1, 0));
                    }
                }
            }
        } else {
            // go in
            int best_queue_size = n + 1;
            int best_id = 0;
            for (int i = 1 ; i <= p ; i++) {
                    // cout << "Pump " << i << endl;
                    // cout << "a " << P[i][tmp.side].have_a << endl;
                    // cout << "b " << P[i][tmp.side].have_b << endl;
                    // cout << "q.size " << P[i][tmp.side].q.size() << endl;
                if (!P[i][tmp.side].have_a) {
                    // open
                    bool _br = false;
                    if (!P[i][tmp.side].have_b) {
                        P[i][tmp.side].have_b = tmp.car_id;
                        _br = true;
                    }
                    else P[i][tmp.side].have_a = tmp.car_id;
                    pq.push(Event(tmp.time + filling_time[tmp.car_id], tmp.car_id, tmp.side, 1, _br));
                    best_id = 0;
                    pump[tmp.car_id] = i;
                    break;
                } else {
                    if (P[i][tmp.side].q.size() < best_queue_size) {
                        best_queue_size = P[i][tmp.side].q.size();
                        best_id = i;
                    }
                }
            }
            // cout << "best_id = " << best_id << endl;
            if (best_id) {
                pump[tmp.car_id] = best_id;
                P[best_id][tmp.side].q.push(tmp.car_id);
            }
            // cout << "pump " << tmp.car_id << " = " << pump[tmp.car_id] << endl;
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        cout << ans[i] << endl;
    }
}