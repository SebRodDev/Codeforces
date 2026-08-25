#include <bits/stdc++.h>
//#include </Users/sebastianrodriguez/stdc++.h>

//using namespace std;

#define usaco
#ifdef usaco
std::ifstream cin("lemonade.in");
std::ofstream cout("lemonade.out");
#endif

int main() {

    int n; cin >> n;

    std::vector<int> nums(n); for (auto& x : nums) cin >> x;

    sort(nums.begin(), nums.end(), std::greater<int>());

    int res = 0;

    for (int num : nums) {
        if (res <= num) {
            res++;
        }
    }

    cout << res << "\n";
}
