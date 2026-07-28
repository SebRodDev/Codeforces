#include <bits/stdc++.h>
#define int long long

#define usaco
//using namespace std;

#ifdef usaco
std::ifstream cin("div7.in");
std::ofstream cout("div7.out");
#endif

int32_t main() {

    // no clear way to shrink sliding window -> dp
    int n; cin >> n;
    std::vector<int> a(n + 1);

    // sum[l..r] % 7 == 0
    // (prefix[r] - prefix[l]) % 7 == 0
    // prefix[r] % 7 == prefix[l] % 7 -> since must be equal we can track if we have already seen this index before
    
    int res = 0;
    std::map<int, int> dp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; a[i] += a[i - 1];
        if (dp.find(a[i] % 7) != dp.end()) {
            res = std::max(res, i - dp[a[i] % 7]);
        } else {
            dp[a[i] % 7] = i;
        }
    }

    cout << res << "\n";
}
