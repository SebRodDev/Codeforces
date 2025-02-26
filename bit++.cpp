// Bit++ CodeForces Problem
// correct solution
#include <iostream>
#include <vector>
#include <ios>

using namespace std;
using vi = vector<int>;

void solve() {
    int n; // number of statements
    cin >> n;
    string operation;
    int x = 0;

    for (int i = 1; i <= n; i++) {
        cin >> operation;

        if (operation[1] == '+') {
            ++x;
        }

        if (operation[1] == '-') {
            --x;
        }
    }

    cout << x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

