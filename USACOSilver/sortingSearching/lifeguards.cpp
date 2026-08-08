//#include <bits/stdc++.h>
#include </Users/sebastianrodriguez/stdc++.h>

#define usaco

#ifdef usaco
std::ifstream cin("lifeguards.in");
std::ofstream cout("lifeguards.out");
#endif

struct Event {
    int time;
    int id;
    bool start;
};

bool operator<(const Event &a, const Event &b) { return a.time < b.time; }

int main() {
    int n; cin >> n;

    std::vector<Event> v;

    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;

        v.push_back({l, i, true});
        v.push_back({r, i, false});
    }

    std::sort(v.begin(), v.end());

    std::vector<int> alone_time(n);

    std::set<int> active;

    int prevTime = 0;

    int total = 0;

    for (Event& e : v) {
        int currTime = e.time;

        if (active.size() > 0) {
            // seeing how much more was added
            total += currTime - prevTime;
        }

        // check to see if there is only 1 cow in this window
        if (active.size() == 1) {
            alone_time[*active.begin()] += currTime - prevTime;
        }

        if (e.start) {
            active.insert(e.id);
        } else {
            active.erase(e.id);
        }

        prevTime = currTime;
    }

    int minTime = *std::min_element(alone_time.begin(), alone_time.end());

    // want to get rid of the minimum covering one?
    cout << total - minTime << "\n";
}
