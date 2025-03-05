// Petya and Strings Problem
#include <iostream>
#include <vector>
#include <ios>

using namespace std;
using vi = vector<int>;

void solve() {
    string first;
    string second;
    cin >> first;
    cin >> second;

    string first_lower;
    string second_lower;

    for (int i = 0; i < first.length(); i++) {
        first_lower += (char) tolower(first[i]);
        second_lower += (char) tolower(second[i]);
    }

    int comparison = first_lower.compare(second_lower);

    if (comparison == 0) {
        cout << 0 << endl;
    }
    else if (comparison < 0) {
        cout << -1 << endl;
    }
    else {
        cout << 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}

