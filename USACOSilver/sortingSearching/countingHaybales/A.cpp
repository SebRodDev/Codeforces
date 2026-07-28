#include <bits/stdc++.h>

#define usaco
//using namespace std;

#ifdef usaco
std::ifstream cin("haybales.in");
std::ofstream cout("haybales.out");
#endif


int main() {
    int n, q; cin >> n >> q;
    std::vector<int> a(n);

    for (auto& x:a) cin >> x;
    std::sort(a.begin(), a.end());

    while (q--) {
        int l, r; cin >> l >> r;

        auto lower = std::lower_bound(a.begin(), a.end(), l);

        auto right = std::upper_bound(a.begin(), a.end(), r);

        int lowIndex = lower - a.begin(), rightIndex = right - a.begin();

        cout << rightIndex - lowIndex << "\n";
    }
}
