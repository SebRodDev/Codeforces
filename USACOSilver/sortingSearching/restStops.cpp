#include <bits/stdc++.h>
//#include </Users/sebastianrodriguez/stdc++.h>

//using namespace std;
#define int long long

#define usaco
#ifdef usaco
std::ifstream cin("reststops.in");
std::ofstream cout("reststops.out");
#endif

int32_t main() {
    int L, N, rf, rb; cin >> L >> N >> rf >> rb;

    std::vector<std::pair<int, int>> arr(N);

    for (auto& x : arr) cin >> x.first >> x.second;

    // stay at the stops that give us the most value

    std::vector<bool> good(N);
    int maxAmt = 0;
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i].second > maxAmt) {
            good[i] = true;
            maxAmt = arr[i].second;
        }
    }

    // now simulate
    int res = 0;
    int prevPos = 0;

    for (int i = 0; i < N; i++) {
        if (good[i]) {
            int travelDist = arr[i].first - prevPos;

            int fTime = travelDist * rf;
            int bTime = travelDist * rb;

            int restTime = fTime - bTime;

            res += restTime * arr[i].second;
            prevPos = arr[i].first;
        }
    }

    cout << res;
}
