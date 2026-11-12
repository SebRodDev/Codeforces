#include <bits/stdc++.h>
//#include </Users/sebastianrodriguez/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    vector<int> ans;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == b[i]) {
            continue;
        }

        // After flipping prefix i+1, the new a[i]
        // will be the inverse of the current a[0].
        if (a[0] == b[i]) {
            // Make a[0] the opposite bit first.
            ans.push_back(1);
            a[0] = (a[0] == '0' ? '1' : '0');
        }

        // Now flipping the prefix will put !a[0] at position i.
        ans.push_back(i + 1);

        reverse(a.begin(), a.begin() + i + 1);
        for (int j = 0; j <= i; j++) {
            a[j] = (a[j] == '0' ? '1' : '0');
        }
    }

    cout << ans.size() << " ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}