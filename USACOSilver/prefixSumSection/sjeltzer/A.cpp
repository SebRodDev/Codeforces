// solution ended up being 6d -> read solution understood implementation is cooked
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

    // giving ranges of values of the ids output the size of the ones whose id val falls between 2 values

    int n; cin >> n;

    // based on the digits???
    vector<string> s(n + 1);
    vector<int> v(n + 1);

    unordered_map<string, int> currentMap;

    // precompute 6 * 3 * 10^5 precomputation since at most 6 digits can just check for all 6 digits
    //
    // 1->6 digit index, 0->9 possible digits
    vector<vector<int>> dp(7, vector<int>(10));

    for (int i = 1; i <= n; i++) {
        string current;
        int value; cin >> current >> value;

        cout << "index : ";
        for (int j = 1; j <= 6; j++) {
            int index = current[j - 1] - '0';
            dp[j][index] += v[i];

            cout << index;
        }

        cout << " " <<  s[i] << "\n\n";
    }

    // prefix sum
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 10; j++) {
            dp[i][j] += dp[i - 1][j - 1];
        }
    }


    int q; cin >> q;

    while (q--) {
        string first, second; cin >> first >> second;

        int res = 0;

        for (int i = 1; i <= 6; i++) {
            res += (dp[i][second[i - 1] - '0'] - dp[i][first[i - 1] - '0' - 1]);
        }

        cout << res << "\n";
    }
}
