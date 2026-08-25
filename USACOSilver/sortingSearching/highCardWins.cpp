#include <bits/stdc++.h>
//#include </Users/sebastianrodriguez/stdc++.h>

//using namespace std;

#define usaco
#ifdef usaco
std::ifstream cin("highcard.in");
std::ofstream cout("highcard.out");
#endif

int main() {

    int n; cin >> n;

    std::vector<int> elise, bessie;
    std::vector<bool> total(2 * n + 1);

    for (int i = 0 ; i < n ; i++) {
        int card; cin >> card;
        total[card] = true;
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (total[i]) {
            elise.push_back(i);
        } else {
            bessie.push_back(i);
        }
    }

    int currentElise = 0, currentBessie = 0;

    int res = 0;
    while (currentElise < elise.size() && currentBessie < bessie.size()) {
        if (bessie[currentBessie] > elise[currentElise]) {
            currentElise++; currentBessie++;
            res++;
        } else {
            currentBessie++;
        }
    }

    cout << res;

}
