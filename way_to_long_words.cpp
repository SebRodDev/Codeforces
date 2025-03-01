// Problem - Way Too Long Words
#include <iostream>
#include <vector>
#include <ios>

using namespace std;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int length = s.length();

        if (length > 10) {
            string result;
            result += s[0]; // adding the first character
            result += to_string(length - 2);
            result += s[length - 1];
            cout << result << endl;
        }
        else {
            cout << s << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}

