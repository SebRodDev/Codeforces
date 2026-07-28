#include <iostream>
#include <vector>
#include <ios>

using namespace std;
using vi = vector<int>;

void solve() {
    int n;
    // receiving the number of test cases
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y; // first digit

        int diff = x + 1 - y;
        if ((diff >= 0) && (diff % 9 == 0)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}

