#include <bits/stdc++.h>
//#include </Users/sebastianrodriguez/stdc++.h>

//using namespace std;
#define int long long

#define usaco

#ifdef usaco
std::ifstream cin("split.in");
std::ofstream cout("split.out");
#endif

std::vector<std::pair<int, int>> cows;

int search(int n) {
    std::sort(cows.begin(), cows.end());

    std::vector<std::pair<int, int>> pref(n), suf(n);

    pref[0] = {cows[0].second, cows[0].second};
    for (int i = 1; i < n; i++) {
        pref[i] = {std::min(pref[i - 1].first, cows[i].second), std::max(pref[i - 1].second, cows[i].second)};
    }

    suf[n - 1] = {cows[n - 1].second, cows[n - 1].second};
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = {std::min(suf[i + 1].first, cows[i].second), std::max(suf[i + 1].second, cows[i].second)};
    }

    int initialArea = (cows.back().first - cows.front().first) * (pref.back().second - pref.back().first);

    int best = LLONG_MAX;

    // consider them in adjacent pairs
    for (int i = 0; i < n - 1; i++) {
        if (cows[i].first != cows[i + 1].first) {
            int firstRec = (cows[i].first - cows[0].first) * (pref[i].second - pref[i].first);
            int secondRec = (cows[n - 1].first - cows[i + 1].first) * (suf[i + 1].second - suf[i + 1].first);

            best = std::min(best, firstRec + secondRec);
        }
    }

    return initialArea - best;
}

int32_t main() {
    // to compute the square for one you would need to find the smallest and largest x values and then smallest/largest y values and that tells
    // you how big the box is

    int n; cin >> n;

    cows.resize(n);

    int res = 0;

    for (std::pair<int, int> & cow: cows) { cin >> cow.first; cin >> cow.second; }

    res = std::max(res, search(n));

    for (std::pair<int, int> & cow : cows) {std::swap(cow.first, cow.second); }

    res = std::max(res, search(n));

    cout << res << "\n";
}
