#include <iostream>
#include <vector>
#include <ios>

using namespace std;
using vi = vector<int>;

void solve() {
    // 2d array so that it holds what we want
    int a[6][6] = {};

    int position[2] {0};

    // making it properly indexed so first point is (1,1)
    for (int i = 1; i < 6; i++) {
        for (int k = 1; k < 6; k++) {
            cin >> a[i][k];

            if (a[i][k] == 1) {
                position[0] = i;
                position[1] = k;
            }
        }
    }

    int x = abs(position[0] - 3);
    int y = abs(position[1] - 3);
    int result = x + y;
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}

