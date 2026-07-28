#include <bits/stdc++.h>

#define usaco
//using namespace std;
#define int long long

#ifdef usaco
std::ifstream cin("socdist.in");
std::ofstream cout("socdist.out");
#endif

bool can(int distance, std::vector<std::pair<int, int>>& grass, int totalCows) {
    int cowsPlaced = 1;

    int lastValue = grass[0].first;
    int currentIdx = 0;

    while (cowsPlaced < totalCows) {
        // seeing how far from current place we have to go
        int target = lastValue + distance;

        // while greater than the right endpoint 
        while (currentIdx < grass.size() && target > grass[currentIdx].second) currentIdx++;

        if (currentIdx == grass.size()) return false;

        lastValue = std::max(target, grass[currentIdx].first);

        cowsPlaced++;
    }

    return true;
}

int32_t main() {

    int n, m; cin >> n >> m;
    std::vector<std::pair<int, int>> grass(m);

    for (int i = 0; i < m; i++) {
        int left, right; cin >> left >> right;

        grass[i] = {left, right};
    }

    std::sort(grass.begin(), grass.end());

    int l = 0, r = 1e9;

    int res = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (can(mid, grass, n)) {
            res = std::max(res, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << res << "\n";
}
