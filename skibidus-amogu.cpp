#include <iostream>
#include <vector>
#include <ios>

using namespace std;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;

    while (--n) {
        string og_s;
        cin >> og_s;

        string remaining = og_s.substr(0, og_s.length() - 2);
        remaining += 'i';

        cout << remaining << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}

