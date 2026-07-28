#include <bits/stdc++.h>

#define usaco
//using namespace std;
#define int long long

#ifdef usaco
std::ifstream cin("cowdance.in");
std::ofstream cout("cowdance.out");
#endif

bool can(int val, std::vector<int>& d, int limit) {
    // how to code the can function????
    // how can you decide if the specific size works
    // sweep line maybe
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;

    int currentSpot = 0;

    while (currentSpot < val && currentSpot < d.size()) {
        heap.push(d[currentSpot++]);
    }

    for (int i = currentSpot; i < d.size(); i++) {
        int earliestEnd = heap.top();

        heap.pop();

        int newTime = earliestEnd + d[i];
        heap.push(newTime);
    }

    int finalTime = 0;
    while (!heap.empty()) {
        finalTime = heap.top();
        heap.pop();
    }
    
    return finalTime <= limit;
}


int32_t main() {
    // want to determine the size of the stage
    // determine the smallest value of K
    
    int n, Tmax; cin >> n >> Tmax;

    std::vector<int> d(n);
    for (auto& x: d) cin >> x;

    int l = 1, r = 10000;

    int res = 1e9;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (can(mid, d, Tmax)) {
            res = std::min(res, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << res << "\n";
}
