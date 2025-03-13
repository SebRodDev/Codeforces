#include <iostream>
#include <vector>
#include <ios>
#include <string>
#include <algorithm>

using namespace std;
using vi = vector<int>;

void solve() {
    string s;
    cin >> s;
    int arr[101];
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '+') {
            arr[count] = s[i] - '0';
            count++;
        }
    }

    sort(arr, arr + count);
    cout << arr[0];
    for (int k = 1; k < count; k++) {
        cout << '+';
        cout << arr[k];
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

