#include <iostream>
#include <vector>
#include <unordered_map>
#include <pair>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n;

    vector<int> num(n);

    unordered_map<int, pair<int, int>> elements;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    cin >> m;
}
