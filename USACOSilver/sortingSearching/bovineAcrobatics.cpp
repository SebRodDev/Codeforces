#include <bits/stdc++.h>
//#include </Users/sebastianrodriguez/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M, K;
    cin >> N >> M >> K;

    vector<pair<long long, long long>> cows(N);

    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end());

    // (top weight, number of towers with this top)
    deque<pair<long long, long long>> dq;

    long long towers = 0;
    long long answer = 0;

    for (auto [w, a] : cows) {
        long long remaining = a;
        long long used = 0;

        // Use existing towers whose top is small enough.
        while (!dq.empty() && remaining > 0) {
            auto [top, cnt] = dq.front();

            if (top + K > w)
                break;

            dq.pop_front();

            long long take = min(cnt, remaining);

            remaining -= take;
            used += take;

            cnt -= take;

            if (cnt > 0) {
                dq.push_front({top, cnt});
                break;
            }
        }

        // If we still have cows, create new towers.
        long long newTowers = min(remaining, M - towers);

        remaining -= newTowers;
        towers += newTowers;

        used += newTowers;

        // All towers used/created with this weight now have top w.
        if (used > 0) {
            dq.push_back({w, used});
        }

        answer += used;
    }

    cout << answer << '\n';
}