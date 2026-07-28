//#include </Users/sebastianrodriguez/stdc++.h>
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

    int n, m, k; cin >> n >> m >> k;

    vector<int> a(n + 1);
    for (int i=1; i <= n; i++) {
        cin >> a[i];
    }


    // operations
    vector<vector<int>> operations(m + 2, vector<int>(3));
    for (int i = 1; i <= m; i++) cin >> operations[i][0] >> operations[i][1] >> operations[i][2];

    // queries
    vector<int> something(m + 2);
    while (k--) {
        int x, y; cin >> x >> y;
        // how many times something is called -> marking that this index should be called more and that the outside the bounds should not be called an additional
        // time -> takes care of some issues where update incorrectly
        something[x]++;
        something[y + 1]--;
    }

    // just do lol
    vector<int> diff(n + 2);
    for (int i = 1; i <= m; i++) {
        something[i] += something[i - 1];

        // basically just inclusive bounding the changes that we made given by how often those changes happen * the value that we want to change
        diff[operations[i][0]] += something[i] * operations[i][2];
        diff[operations[i][1] + 1] -= something[i] * operations[i][2];
    }

    for (int i = 1; i <= n; i++) {
        // basically just accumulate the differences for the things we have made
        diff[i] += diff[i - 1];
        cout << a[i] + diff[i] << " ";
    }
}

