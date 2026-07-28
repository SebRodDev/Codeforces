#include <bits/stdc++.h>

#define usaco
//using namespace std;
#define int long long

#ifdef usaco
std::ifstream cin("angry.in");
std::ofstream cout("angry.out");
#endif

bool can(int power, std::vector<int>& x, int k) {
    int amountK = 0;

    // forgot to consider the numerical distances and just going off of the indexes instead
    int earliestDistance = x[0];

    int current = 1;

    while (current < x.size()) {
        if (x[current] - earliestDistance > power + power) {
            amountK++;
            earliestDistance = x[current];
            current++;
            continue;
        }

        current++;
    }


    return amountK + 1 <= k;
}


int32_t main() {
    // compute min integer of R such that we use the K cows to touch every single haybale
    // bsta on R

    int N, K; cin >> N >> K;

    std::vector<int> x(N); for (auto& a : x) cin >> a;
    std::sort(x.begin(), x.end());

    int l = 0, r = 1e9;

    int res = 1e9;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (can(mid, x, K)) {
            res = std::min(res, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }

    }

    cout << res << "\n";

}
