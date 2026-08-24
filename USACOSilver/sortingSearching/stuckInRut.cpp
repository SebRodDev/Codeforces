#include <bits/stdc++.h>
//#include </Users/sebastianrodriguez/stdc++.h>

using namespace std;
#define int long long


struct Cow {
    int id;
    char dir;
    int x, y;
};

struct CandidateIntersection {
    int east_cow_id;
    int north_cow_id;
    long long x; // Intersection X coordinate (x_N)
    long long y; // Intersection Y coordinate (y_E)
    long long t_east; // Time when East cow arrives
    long long t_north; // Time when North cow arrives
};

int countBlame(int id, const std::map<int, std::set<int>>& amountClosed, std::vector<int>& dp) {
    if (dp[id] != -1) return dp[id];


    if (amountClosed.count(id) == 0) {
        return dp[id] = 0;
    }

    int total = 0;

    for (int neighbor : amountClosed.at(id)) {
        total += 1 + countBlame(neighbor, amountClosed, dp);
    }

    return dp[id] = total;
}

int32_t main() {
    // only care about the intersection points
    // can do n^2 operations to precompute it
    std::vector<Cow> eastCows, northCows;

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        char d; int x, y; cin >> d >> x >> y;

        if (d == 'E') {
            eastCows.push_back({i, d, x, y});
        } else {
            northCows.push_back({i, d, x, y});
        }
    }

    vector<CandidateIntersection> intersections;
    for (auto& eastCow : eastCows) {
        for (auto& northCow : northCows) {
            if (eastCow.x <= northCow.x && eastCow.y >= northCow.y) {
                // finding whichever place they collide first
                int timeEast = northCow.x - eastCow.x;
                int timeNorth = eastCow.y - northCow.y;

                intersections.push_back({eastCow.id, northCow.id, northCow.x, eastCow.y, timeEast, timeNorth});
            }
        }
    }

    // sorting by when the stopping actually happens
    sort(intersections.begin(), intersections.end(),
    [](const CandidateIntersection& a, const CandidateIntersection& b) {
        return max(a.t_east, a.t_north) <
               max(b.t_east, b.t_north);
    });

    std::map<int, std::set<int>> amountClosed;
    std::vector<int> stoppedTime(n + 1, 1e18);

    for (auto& intersection : intersections) {
        if (intersection.t_east != intersection.t_north) {
            if (stoppedTime[intersection.east_cow_id] >= intersection.t_east && stoppedTime[intersection.north_cow_id] >= intersection.t_north) {

                if (intersection.t_east < intersection.t_north) {
                    // east cow got there first
                    stoppedTime[intersection.north_cow_id] = intersection.t_north;

                    amountClosed[intersection.east_cow_id].insert(intersection.north_cow_id);
                } else {
                    // north cow got there first
                    stoppedTime[intersection.east_cow_id] = intersection.t_east;

                    amountClosed[intersection.north_cow_id].insert(intersection.east_cow_id);
                }
            }
        }
    }

    std::vector<int> res(n, 0);
    std::vector<int> dp(n, -1);
    for (int i = 0; i <n; i++) {
        res[i] = countBlame(i, amountClosed, dp);
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << "\n";
    }
}
