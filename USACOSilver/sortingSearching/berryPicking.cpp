#include <bits/stdc++.h>
//#include </Users/sebastianrodriguez/stdc++.h>

//using namespace std;

#define usaco
#ifdef usaco
std::ifstream cin("berries.in");
std::ofstream cout("berries.out");
#endif

int main() {

    int n, k; cin >> n >> k;

    std::vector<int> a(n); for (auto &i : a) cin >> i;

    int res = 0;
    for (int i = 1; i <= 1000; i++) {
        int elsie = k / 2;
        int bessie = k / 2;

        std::vector<int> remaining;

        for (int j = 0; j < n; j++) {
            int totalFill = a[j] / i;

            int totalElsie = std::min(totalFill, elsie);

            elsie -= totalElsie;

            // anything that didnt go to elsie can go to bessie
            for (int k = 0; k < totalFill - totalElsie; k++) {
                remaining.push_back(i);
            }

            if (a[j] % i > 0) {
                remaining.push_back(a[j] % i);
            }
        }

        if (elsie <= 0) {
            std::sort(remaining.rbegin(), remaining.rend());

            int current = 0;
            for (int t = 0; t < bessie && t < remaining.size(); t++) {
                current += remaining[t];
            }

            res = std::max(res, current);
        }
    }

    cout << res;
}
