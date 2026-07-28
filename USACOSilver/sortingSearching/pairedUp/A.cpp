#include <bits/stdc++.h>

#define usaco

#ifdef usaco
std::ifstream cin("pairup.in");
std::ofstream cout("pairup.out");
#endif
int main() {
    int n; cin >> n;

    // split in half based on amount of cows
    // want to get get as close to half of the amount of time as possible
    
    // 2 indices that their sum is like equal or something to half -> sounds like greedy
    std::vector<std::pair<int, int>> a;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a.push_back({y, x});
    }

    std::sort(a.begin(), a.end());

    int left = 0, right = n - 1, res = 0;

    while (left <= right) {
        int amtLeft = std::min(a[left].second, a[right].second);

        // if at same point just split in half
        if (left == right) amtLeft /= 2;

        res = std::max(res, a[left].first + a[right].first);

        // just trying to match up largest with smallest
        a[left].second -= amtLeft;
        a[right].second -= amtLeft;

        if (a[left].second == 0) left++;
        if (a[right].second == 0) right--;
    }

    cout << res << "\n";
}
