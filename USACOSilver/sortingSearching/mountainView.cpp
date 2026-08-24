#include <bits/stdc++.h>
//#include </Users/sebastianrodriguez/stdc++.h>

#define int long long

#define usaco
#ifdef usaco
std::ifstream cin("mountains.in");
std::ofstream cout("mountains.out");
#endif

int32_t main() {
    // pretty obvious that the largest y axis will clearly be seen from the xy plane
    // cant n^2 obviously
    // the points given are stated to be un ique so we can maybe coordinate compress them

    int n; cin >> n;

    std::vector<std::pair<int, int>> mountains;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;

        mountains.push_back({x - y, x + y});
    }

    std::sort(mountains.begin(), mountains.end());

    // for each x if not hidden find the point such that all to the left of it have an x value of x - height
    // same with the right side binary search to find the value of x - height and then idk

    int rightMost = -1, res = 0;

    for (auto& mountain : mountains) {
        if (mountain.second > rightMost) {
            res++;
            rightMost = mountain.second;
        }
    }

    cout << res << "\n";
}
