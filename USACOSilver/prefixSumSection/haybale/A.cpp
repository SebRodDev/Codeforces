#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    vector<int> vals(n + 2);


    // do all operations
    while (k--) {
        int A, B; cin >> A >> B;
        vals[A]++; vals[B + 1]--;
    }

    for (int i = 1; i < n + 2; i++) vals[i] += vals[i - 1];

    sort(vals.begin() + 1, vals.begin() + n);

    cout << vals[n / 2] << "\n";

}
