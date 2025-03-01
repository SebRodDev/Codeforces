// Problem - String Task
#include <iostream>
#include <vector>
#include <ios>

using namespace std;
using vi = vector<int>;

void solve() {
    string s;
    cin >> s;

    int length = s.length();

    string result;
    for (int i = 0; i < length; i++) {
        char current = (char) tolower(s[i]);

        if (!((current == 'a') || (current == 'e') || (current == 'i') || (current == 'o') || (current == 'u') || (current == 'y'))) {
            result += '.';
            result += current;
        }
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}

