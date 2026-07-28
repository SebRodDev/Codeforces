#include <bits/stdc++.h>

using namespace std;
#define int long long

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif
 
template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;

    map<int, int> values;
    // basically want to track the most frequent spots that are hit and place the largest numbers in those positions then
    // just answer the queries simple enough 
    for (int i = 0; i < n; i++) {
        int current; cin >> current;
        values[current]++;
    }

    vector<int> position(n + 2);

    vector<pair<int, int>> queries(q);

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;

        position[l]++; position[r + 1]--;
        queries[i] = {l, r};
    }

    map<int, vector<int>> sortedIndexes;
    for (int i = 1; i <= n; i++) {
        position[i] += position[i - 1];

        sortedIndexes[position[i]].push_back(i);
    }

    // populate array with appropriate values
    auto valPoint = values.end(); valPoint--;

    vector<int> finalA(n + 2);
    for (auto it = sortedIndexes.rbegin(); it != sortedIndexes.rend(); it++) {
        vector<int> availableIndexes = it->second; 
        // fill the values appropriately
        for (int index : availableIndexes) {
            while (valPoint->second == 0) valPoint--;

            finalA[index] = valPoint->first;
            valPoint->second--;
        }

        if (valPoint->second <= 0) valPoint--;
    }

    for (int i =1; i <= n; i++) finalA[i] += finalA[i - 1];

    int res = 0;
    for (auto [l, r] : queries) {
        res += finalA[r] - finalA[l - 1];
    }

    cout << res << "\n";
}
