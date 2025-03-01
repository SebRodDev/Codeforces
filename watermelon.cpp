// Watermelon problem

#include <iostream>
#include <vector>
#include <ios>

using namespace std;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "NO" << endl;
        return;
    }

    if (n % 2 == 0) {
    if (n == 2) {
        cout << "NO" << endl;
    }
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}

