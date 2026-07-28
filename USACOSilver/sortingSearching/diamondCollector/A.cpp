#include <bits/stdc++.h>
#define int long long
//using namespace std;

#define usaco

#ifdef usaco
std::ifstream cin("diamond.in");
std::ofstream cout("diamond.out");
#endif

int32_t main() {
    // determine max amount of diamonds she can display in both cases
    // largest and smallest diamonds in the case cannot differ by a size of more than k
    int n, k; cin >> n >> k;

    std::vector<int> a(n); for (auto &x : a) cin >> x;

    std::sort(a.begin(), a.end());

    // find largest 2 non-overlapping windows and just add them to get final
    int l = 0, r = 0;

    std::vector<int> amtLeft(n);

    // seeing how many diamonds can be taken if l is our left boundary
    while (l < n) {
        while (r < n && a[r] - a[l] <= k) r++;

        // know at index r it dont work so dont have to have + 1
        amtLeft[l] = r - l;
        l++;
    }

    std::vector<int> amtRight(n + 1);
    amtRight[n] = 0;

    for (int i = n - 1; i >= 0; i--) 
        // best that we could have at the right is either including index i or not including the index
        // either take the largest window that can be made there or we take the larger window to the right
        amtRight[i] = std::max(amtRight[i + 1], amtLeft[i]);

    int res = 0;

    for (int i = 0; i < n; i++) res= std::max(res,amtLeft[i] + amtRight[i + amtLeft[i]]);

    cout<<res<<"\n";
}
