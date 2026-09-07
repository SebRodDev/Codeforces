#include <bits/stdc++.h>
//#include </Users/sebastianrodriguez/stdc++.h>

using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (auto &x: v) cin >> x;

        string s;
        cin >> s;

        int inversions = 0, oneCount = 0, zeroCount = 0;

        for (int i = 0; i < n; i++) {
            if (v[i]) {
                oneCount++;
            } else {
                inversions += oneCount;
                zeroCount++;
            }
        }

        // l = beginning of active section
        // r = end of active section
        int l = 0, r = n - 1;

        auto simplify = [&]() {
            while (l <= r && v[l] == 0) {
                zeroCount--;
                l++;
            }

            while (l <= r && v[r] == 1) {
                oneCount--;
                r--;
            }
        };

        cout << inversions << " ";

        for (char c: s) {
            simplify();

            if (l > r) {
                cout << 0 << " ";
                continue;
            }

            if (c == '1') {
                // Move the leftmost 1 to the right.
                inversions -= zeroCount;

                // That leftmost 1 is v[l].
                l++;
                oneCount--;
            } else {
                // Move the rightmost 0 to the left.
                inversions -= oneCount;

                // That rightmost 0 is v[r].
                r--;
                zeroCount--;
            }

            cout << inversions << " ";
        }
        cout << "\n";
    }
}
