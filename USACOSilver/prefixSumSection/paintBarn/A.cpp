#include <bits/stdc++.h>

//using namespace std;

#define usaco
#define int long long

#ifdef usaco
std::ifstream cin("paintbarn.in");
std::ofstream cout("paintbarn.out");
#endif

int32_t main() {
    std::ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;

    std::vector<std::vector<int>> a(1002, std::vector<int>(1002));

    while (n--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        a[x1 + 1][y1 + 1]++; a[x1 + 1][y2 + 1]--; a[x2 + 1][y1 + 1]--; a[x2 + 1][y2 + 1]++;
    }

    // prefix sum
    // area of the barn -> just count squares

    int count = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (a[i][j] == k) count++;
        }
    }

    cout << count << "\n";
}
