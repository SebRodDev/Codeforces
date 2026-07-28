#include <bits/stdc++.h>

#define usaco
//using namespace std;
#define int long long

#ifdef usaco
std::ifstream cin("convention.in");
std::ofstream cout("convention.out");
#endif

bool can(int time, std::vector<int>& d, int busAmount, int cowPerBus) {
    // take min of the window and just see how many cows can be added given val is 
    // our longest waiting time

    int amountBuses = 0;

    int currentCowCount = 1;
    int currentEarliestArrival = d[0];
    int i = 1;
    while (i < d.size()) {
        // if time wait exceeds the stop then just have it go on a new bus
        
        // if at cow capacity
        if (currentCowCount == cowPerBus) {
            amountBuses++;
            currentEarliestArrival = d[i];
            currentCowCount = 1;
            i++;
            continue;
        }

        // now check if the time difference between arrival and earliest time cur cow gets there is <= time
        int timeDifference = std::abs(currentEarliestArrival - d[i]);

        if (timeDifference > time) {
            amountBuses++;
            currentCowCount = 1;
            currentEarliestArrival = d[i];
        } else {
            currentCowCount++;
        }

        currentEarliestArrival = std::min(currentEarliestArrival, d[i]);
        i++;
    }

    // if it takes more buses at that max time to wait then we know this max time will not work
    return amountBuses + 1 <= busAmount;
}


int32_t main() {
    int n, m, c; cin >> n >> m >> c;

    std::vector<int> t(n); for (auto& x : t) cin >> x;
    std::sort(t.begin(), t.end());

    int l = 0, r = 1e9;

    int res = 1e9;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (can(mid, t, m, c)) {
            res = std::min(res, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << res << "\n";
}
