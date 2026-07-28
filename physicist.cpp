#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<vector<int>> vectors;

    while (n--) {
        vector<int> current;
        int x, y, z; cin >> x >> y >> z;
        current.push_back(x);
        current.push_back(y);
        current.push_back(z);
        vectors.push_back(current);
    }

    int x_sum, y_sum, z_sum;
    x_sum = y_sum = z_sum = 0;
    for (int i = 0; i < vectors.size(); i++) {
        x_sum += vectors[i][0];
        y_sum += vectors[i][1];
        z_sum += vectors[i][2];
    }
    
    if (x_sum != 0 || y_sum != 0 || z_sum != 0) {
        cout << "NO" << "\n";
        return 0;
    }

    cout << "YES" << "\n";
}
