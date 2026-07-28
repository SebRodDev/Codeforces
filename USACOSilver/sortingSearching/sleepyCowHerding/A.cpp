#include <bits/stdc++.h>

#define usaco

#ifdef usaco
std::ifstream cin("herding.in");
std::ofstream cout("herding.out");
#endif

int main() {

    // max amount of moves is just moving each outer cow to the min possible position
    // that it can take up such that its no longer and endpoint among all the cows
    //
    // min amount is like optimally moving the cow to positions that are closest to all other cows and 
    // basically group them together
    int n;cin>>n;

    std::vector<int> a(n);

    for (auto& x : a) cin >> x;
    std::sort(a.begin(), a.end());

    // computing min
    
    // account for both edge cases
    int minAmt = 0;
    if (a[n - 2] - a[0] == n - 2 && a[n - 1] - a[n - 2] > 2) {
        minAmt = 2;
    } else if (a[n - 1] - a[1] == n - 2 && a[1] - a[0] > 2) {
        minAmt = 2;
    } else {
        // looping through
        int l = 0, r = 0;
        int maxRange = 0;

        for (l = 0; l < n; l++) {
            while (r < n - 1 && a[r + 1] - a[l] <= n - 1) {
                // finding the largest range of consecutive cows
                r++;
            }

            maxRange = std::max(maxRange, r - l + 1);
        }

        // basically would have to move them to the spaces in between and its just whatever is left over between
        // largest set of consecutive cows
        minAmt = n - maxRange;
    }

    // finding the max
    // basically just swapping our farthest right or farthest left pair over and over to get to fill in the missing spots
    // finding max amount of spaces and on which side it is then
    int maxAmt = std::max(a[n - 2] - a[0], a[n - 1] - a[1]) - (n - 2);

    cout << minAmt<<"\n"<<maxAmt<<"\n";
}
