#include <bits/stdc++.h>

//using namespace std;

#define usaco

#ifdef usaco
std::ifstream cin("bcount.in");
std::ofstream cout("bcount.out");
#endif

int main() {
    std::ios::sync_with_stdio(false);

    int n, q; cin >> n >> q;

    // 1, 2, 3
    std::vector<std::vector<int>> nums(n + 1, std::vector<int>(3, 0));

    int first = 0;
    int second = 0;
    int third = 0;

    for (int i = 1; i <= n; i++) {
        int c; cin >> c;
        switch(c) {
            case 1:
                first++;
                break;
            case 2:
                second++;
                break;
            case 3:
                third++;
                break;
        }

        nums[i][0] = first;
        nums[i][1] = second;
        nums[i][2] = third;
    }

    while (q--) {
        int a, b; cin >> a >> b;

        if (a > 0 && b > 0) {
            cout << nums[b][0] - nums[a - 1][0] << " " << nums[b][1] - nums[a - 1][1] << " " << nums[b][2] - nums[a - 1][2] << "\n";
        } else {
            cout << nums[b][0] << " " << nums[b][1] << " " << nums[b][2] << "\n";
        }
    }
}
