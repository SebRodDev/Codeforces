#include <bits/stdc++.h>
//#include </Users/sebastianrodriguez/stdc++.h>

#define int long long

#define usaco
#ifdef usaco
std::ifstream cin("cardgame.in");
std::ofstream cout("cardgame.out");
#endif

int32_t main() {
    int n; cin >> n;

    std::vector<int> eLeft, eRight;
    std::vector<int> b;
    std::vector<bool> allCards(2 * n + 1);

    for (int i = 0; i < n; i++) {
        int card; cin >> card;
        allCards[card] = true;

        if (i < n / 2) {
            eLeft.push_back(card);
        } else {
            eRight.push_back(card);
        }
    }

    sort(eLeft.begin(), eLeft.end());
    sort(eRight.begin(), eRight.end());

    for (int i = 1; i <= 2 * n; i++) {
        if (!allCards[i]) {
            b.push_back(i);
        }
    }

    std::set<int> bLeft, bRight;

    for (int i = 0; i < b.size(); i++) {
        if (i < n / 2) {
            bRight.insert(b[i]);
        } else {
            bLeft.insert(b[i]);
        }
    }

    // now go through the left side then right side for the solution

    int res = 0;

    // go through left
    for (int num : eLeft) {
        auto found = bLeft.lower_bound(num);

        if (found != bLeft.end()) {
            res++;
            bLeft.erase(found);
        }
    }

    for (int num : eRight) {
        auto found = bRight.lower_bound(num);
        if (found != bRight.begin()) {
            found--;
            res++;
            bRight.erase(found);
        }
    }

    cout << res;
}
